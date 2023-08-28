#ifndef TABLE_ENGINE_DICTTOMAP_H
#define TABLE_ENGINE_DICTTOMAP_H

#include "ListToVector.h"
#include "engine.h"
#include "exception_collection.h"

template <typename T>
class DictToMap {
   public:
    typedef T native_type;

    explicit DictToMap() {
        py::converter::registry::push_back(&DictToMap<native_type>::convertible,
                                           &DictToMap<native_type>::construct,
                                           py::type_id<native_type>());
        py::to_python_converter<native_type, DictToMap<native_type>>();
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
        try {
            fillMapFromDict(py_object, storage);
        } catch (std::exception e) {
            delete storage;
            throw ConverterException(e.what());
        }

        data->convertible = storage;
    }

    static void fillMapFromDict(PyObject *py_object,
                                native_type *const storage) {
        auto keys = PyMapping_Keys(py_object);
        for (py::ssize_t i = 0, l = PySequence_Size(keys); i < l; ++i) {
            auto value =
                PyObject_GetItem(py_object, PySequence_GetItem(keys, i));
            typename native_type::mapped_type resValue;

            if (PyList_Check(value)) {
                if (typeid(typename native_type::mapped_type) ==
                    typeid(cpp_dec_float_50)) {
                    std::vector<double> valueVector = toVector<double>(value);
                    resValue = boost::accumulate(valueVector, double(0));
                    valueVector.clear();
                } else {
                    std::vector<typename native_type::mapped_type> valueVector =
                        toVector<typename native_type::mapped_type>(value);
                    resValue = boost::accumulate(
                        valueVector, typename native_type::mapped_type(0));
                    valueVector.clear();
                }

            } else {
                resValue =
                    py::extract<typename native_type::mapped_type>(value)();
            }

            static_assert(!std::is_same<typename native_type::mapped_type,
                                        boost::any>::value,
                          "Mapped_type can't be boost::any");
            storage->insert(
                std::make_pair(py::extract<typename native_type::key_type>(
                                   PySequence_GetItem(keys, i))(),
                               resValue));
        }
    }

    template <typename _T>
    static std::vector<_T> toVector(PyObject *py_list) {
        std::vector<_T> valueVector;
        ListToVector<std::vector<_T>>::fillVectorFromList(py_list,
                                                          &valueVector);

        return valueVector;
    }

    static PyObject *convert(const native_type node) {
        try {
            py::dict py_element;

            BOOST_FOREACH (auto m_pair, node) {
                if (typeid(typename native_type::mapped_type) ==
                    typeid(cpp_dec_float_50)) {
                    py_element[m_pair.first] = py::object(
                        boost::lexical_cast<long double>(m_pair.second));
                } else
                    py_element[m_pair.first] = m_pair.second;
            }

            return py::incref(py_element.ptr());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_DICTTOMAP_H
