#ifndef TABLE_ENGINE_DICTTOMAPDYNAMICVALUE_H
#define TABLE_ENGINE_DICTTOMAPDYNAMICVALUE_H

#include "ToDynamicValue.h"
#include "engine.h"
#include "exception_collection.h"

template <typename T>
class DictToMapDynamicValue {
   public:
    typedef T native_type;

    explicit DictToMapDynamicValue() {
        py::converter::registry::push_back(
            &DictToMapDynamicValue<native_type>::convertible,
            &DictToMapDynamicValue<native_type>::construct,
            py::type_id<std::map<native_type, DynamicValue>>());
        py::to_python_converter<std::map<native_type, DynamicValue>,
                                DictToMapDynamicValue<native_type>>();
    }

    static void *convertible(PyObject *py_object) {
        if (!PyMapping_Check(py_object)) return nullptr;
        return py_object;
    }

    static void construct(PyObject *py_object,
                          py::converter::rvalue_from_python_stage1_data *data) {
        //! Placing an object in allocated memory (Replaced New)
        auto storage =
            new (reinterpret_cast<py::converter::rvalue_from_python_storage<
                     std::map<native_type, DynamicValue>> *>(data)
                     ->storage.bytes) std::map<native_type, DynamicValue>;
        //! Serialize new values
        try {
            fillMapFromDict(py_object, storage);
        } catch (std::exception e) {
            delete storage;
            throw ConverterException(e.what());
        }
        data->convertible = storage;
    }

    static void fillMapFromDict(
        PyObject *py_object,
        std::map<native_type, DynamicValue> *const storage) {
        auto keys = PyMapping_Keys(py_object);

        for (py::ssize_t i = 0, l = PySequence_Size(keys); i < l; ++i) {
            auto value =
                PyObject_GetItem(py_object, PySequence_GetItem(keys, i));

            storage->insert(std::make_pair(
                py::extract<native_type>(PySequence_GetItem(keys, i))(),
                ToDynamicValue::getValue(value)));
        }
    }

    static PyObject *convert(std::map<native_type, DynamicValue> node) {
        try {
            py::dict py_element;

            BOOST_FOREACH (auto &m_pair, node) {
                py_element[m_pair.first] =
                    ToDynamicValue::toObject(m_pair.second);
            }

            return py::incref(py_element.ptr());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_DICTTOMAPDYNAMICVALUE_H
