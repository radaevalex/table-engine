#ifndef TABLE_ENGINE_DICTTOMAPMAP_H
#define TABLE_ENGINE_DICTTOMAPMAP_H

#include "DictToMap.h"
#include "engine.h"
#include "exception_collection.h"

template <typename T>
class DictToMapMap {
   public:
    typedef T native_type;

    DictToMapMap() {
        py::converter::registry::push_back(&DictToMapMap<T>::convertible,
                                           &DictToMapMap<T>::construct,
                                           py::type_id<T>());
        py::to_python_converter<T, DictToMapMap<T>>();
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
                py::converter::rvalue_from_python_storage<native_type> *>(data)
                ->storage.bytes) native_type;
        //! Serialize new values
        fillMapFromDict(py_object, storage);
        data->convertible = storage;
    }

    static void fillMapFromDict(PyObject *py_object,
                                native_type *const storage) {
        auto keys = PyMapping_Keys(py_object);
        for (py::ssize_t i = 0, l = PySequence_Size(keys); i < l; ++i) {
            auto value =
                PyObject_GetItem(py_object, PySequence_GetItem(keys, i));
            typename native_type::mapped_type resValue;
            DictToMap<typename native_type::mapped_type>::fillMapFromDict(
                value, &resValue);

            static_assert(!std::is_same<typename native_type::mapped_type,
                                        boost::any>::value,
                          "Mapped_type can't be boost::any");
            storage->insert(
                std::make_pair(py::extract<typename native_type::key_type>(
                                   PySequence_GetItem(keys, i))(),
                               resValue));
        }
    }

    static PyObject *convert(const native_type node) {
        try {
            py::dict py_element;

            BOOST_FOREACH (auto &m_pair, node) {
                auto elem =
                    DictToMap<typename native_type::mapped_type>::convert(
                        m_pair.second);
                py::object elem_obj(py::handle<>(py::borrowed(elem)));
                py_element[m_pair.first] = elem_obj;
            }

            return py::incref(py_element.ptr());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_DICTTOMAPMAP_H
