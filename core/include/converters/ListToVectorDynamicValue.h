#ifndef TABLE_ENGINE_LISTTOVECTORDYNAMICVALUE_H
#define TABLE_ENGINE_LISTTOVECTORDYNAMICVALUE_H

#include "converters/ToDynamicValue.h"
#include "engine.h"
#include "exception_collection.h"

class ListToVectorDynamicValue {
   public:
    ListToVectorDynamicValue() {
        py::converter::registry::push_back(
            &ListToVectorDynamicValue::convertible,
            &ListToVectorDynamicValue::construct,
            py::type_id<std::vector<DynamicValue>>());
        py::to_python_converter<std::vector<DynamicValue>,
                                ListToVectorDynamicValue>();
    }

    static void *convertible(PyObject *py_object) {
        if (!PySequence_Check(py_object)) return nullptr;
        return py_object;
    }

    static void construct(PyObject *pyo,
                          py::converter::rvalue_from_python_stage1_data *data) {
        //! Placing an object in allocated memory (Replaced New)
        std::vector<DynamicValue> *storage =
            new (reinterpret_cast<py::converter::rvalue_from_python_storage<
                     std::vector<DynamicValue>> *>(data)
                     ->storage.bytes) std::vector<DynamicValue>();
        fillVectorFromList(pyo, storage);
        data->convertible = storage;
    }

    static void fillVectorFromList(PyObject *py_object,
                                   std::vector<DynamicValue> *const storage) {
        for (py::ssize_t i = 0, l = PySequence_Size(py_object); i < l; ++i) {
            storage->push_back(
                ToDynamicValue::getValue(PySequence_GetItem(py_object, i)));
        }
    }

    static py::list toObject(const std::vector<DynamicValue> &native_list) {
        py::list py_list;

        BOOST_FOREACH (auto &value, native_list) {
            py_list.append(ToDynamicValue::toObject(value));
        }
        return py_list;
    }

    static PyObject *convert(const std::vector<DynamicValue> native_list) {
        try {
            return py::incref(
                ListToVectorDynamicValue::toObject(native_list).ptr());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_LISTTOVECTORDYNAMICVALUE_H
