#ifndef TABLE_ENGINE_TODYNAMICVALUE_H
#define TABLE_ENGINE_TODYNAMICVALUE_H

#include "ListToVector.h"
#include "engine.h"
#include "exception_collection.h"

class ToDynamicValue {
   public:
    explicit ToDynamicValue() {
        py::converter::registry::push_back(&ToDynamicValue::convertible,
                                           &ToDynamicValue::construct,
                                           py::type_id<DynamicValue>());
        py::to_python_converter<DynamicValue, ToDynamicValue>();
    }

    static void *convertible(PyObject *py_object) {
        if (!PyMapping_Check(py_object)) return nullptr;
        return py_object;
    }

    static void construct(PyObject *py_object,
                          py::converter::rvalue_from_python_stage1_data *data) {
        //! Placing an object in allocated memory (Replaced New)
        auto storage = new (
            reinterpret_cast<
                py::converter::rvalue_from_python_storage<DynamicValue> *>(data)
                ->storage.bytes) DynamicValue;
        //! Serialize new values
        try {
            fillMapFromDict(py_object, storage);
        } catch (std::exception e) {
            delete storage;
            throw ConverterException(e.what());
        }

        data->convertible = storage;
    }

    static void fillMapFromDict(PyObject *py_object,
                                DynamicValue *const storage) {
        (*storage) = getValue(py_object);
    }

    static DynamicValue getValue(PyObject *py_value) {
        DynamicValue resValue;

        PyDateTime_IMPORT;

        if (py_value == Py_None) {
            resValue = {DvType::TYPE_NONE, cpp_dec_float_50(0)};
        } else if (PyList_Check(py_value)) {
            if (not PySequence_Size(py_value)) {
                resValue = {DvType::TYPE_NONE, cpp_dec_float_50(0)};

            } else if (py_all_of(py_value, PyNumber_Check)) {
                std::vector<long double> valueVector;
                ListToVector<std::vector<long double>>::fillVectorFromList(
                    py_value, &valueVector);
                resValue = {DvType::TYPE_NUMBER,
                            static_cast<cpp_dec_float_50>(
                                boost::accumulate(valueVector, double(0)))};
                valueVector.clear();
            } else {
                resValue = {DvType::TYPE_STRING,
                            py::extract<std::string>(
                                PySequence_GetItem(py_value, 0))()};
            }
        } else if (PyNumber_Check(py_value) || PyFloat_Check(py_value)) {
            resValue = {DvType::TYPE_NUMBER,
                        static_cast<cpp_dec_float_50>(
                            py::extract<long double>(py_value)())};
        } else if (PyBytes_Check(py_value) || PyUnicode_Check(py_value)) {
            resValue = {DvType::TYPE_STRING,
                        py::extract<std::string>(py_value)()};
        } else if (PyDateTime_Check(py_value)) {
            PyObject *py_timestamp =
                PyObject_CallMethod(py_value, "timestamp", NULL);
            resValue = {DvType::TYPE_DATETIME,
                        static_cast<cpp_dec_float_50>(
                            py::extract<double>(py_timestamp)())};
        } else if (PyDate_Check(py_value)) {
            py::object pyTime = py::import("time");

            py::object py_timestamp = pyTime.attr("mktime")(
                boost::python::handle<>(boost::python::borrowed(
                    PyObject_CallMethod(py_value, "timetuple", NULL))));

            resValue = {DvType::TYPE_DATE,
                        static_cast<cpp_dec_float_50>(
                            py::extract<double>(py_timestamp)())};
        } else if (PyTime_Check(py_value)) {
            std::tm tdate = {PyDateTime_TIME_GET_SECOND(py_value),
                             PyDateTime_TIME_GET_MINUTE(py_value),
                             PyDateTime_TIME_GET_HOUR(py_value),
                             1,
                             0,
                             70};

            resValue = {DvType::TYPE_TIME, cpp_dec_float_50(timelocal(&tdate))};
        } else {
            resValue = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
        }

        return resValue;
    }

    static bool py_all_of(PyObject *py_list,
                          std::function<bool(PyObject *)> pred) {
        for (py::ssize_t i = 0, l = PySequence_Size(py_list); i < l; ++i) {
            auto elem = PySequence_GetItem(py_list, i);
            if (not pred(elem)) {
                return false;
            }
        }
        return true;
    }

    static py::object toObject(DynamicValue rvalue) {
        py::object py_object;

        PyDateTime_IMPORT;

        if (rvalue.type == DvType::TYPE_NUMBER) {
            auto value = static_cast<long double>(
                boost::any_cast<cpp_dec_float_50>(rvalue.value));

            if (boost::math::isnan(value) || boost::math::isinf(value)) {
                py_object = py::object("N/A");
            } else if (static_cast<int>(value) == value) {
                py_object = py::object(static_cast<int>(value));
            } else {
                py_object = py::object(value);
            }
        } else if (rvalue.type == DvType::TYPE_STRING) {
            py_object = py::object(boost::any_cast<std::string>(rvalue.value));
        } else if (rvalue.type == DvType::TYPE_BOOLEAN) {
            py_object = py::object(static_cast<bool>(
                boost::any_cast<cpp_dec_float_50>(rvalue.value)));
        } else if (rvalue.type == DvType::TYPE_TIME) {
            time_t time_value =
                (int)boost::any_cast<cpp_dec_float_50>(rvalue.value);
            auto tdate = std::localtime(&time_value);
            py_object = py::object(
                boost::python::handle<>(boost::python::borrowed(PyTime_FromTime(
                    tdate->tm_hour, tdate->tm_min, tdate->tm_sec, 0))));
        } else if (rvalue.type == DvType::TYPE_DATE) {
            py_object = py::object(boost::python::handle<>(
                boost::python::borrowed(PyDate_FromTimestamp(Py_BuildValue(
                    "(O)",
                    PyFloat_FromDouble(static_cast<double>(
                        boost::any_cast<cpp_dec_float_50>(rvalue.value))))))));
        } else if (rvalue.type == DvType::TYPE_DATETIME) {
            py_object = py::object(boost::python::handle<>(
                boost::python::borrowed(PyDateTime_FromTimestamp(Py_BuildValue(
                    "(O)",
                    PyFloat_FromDouble(static_cast<double>(
                        boost::any_cast<cpp_dec_float_50>(rvalue.value))))))));
        } else if (rvalue.type == DvType::TYPE_NONE) {
            py_object = py::object();
        } else if (rvalue.type == DvType::TYPE_OTHER) {
            py_object = py::object("N/A");
        }

        return py_object;
    }

    static PyObject *convert(DynamicValue rvalue) {
        try {
            return py::incref(ToDynamicValue::toObject(rvalue).ptr());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_TODYNAMICVALUE_H
