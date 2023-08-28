#ifndef TABLE_ENGINE_LISTTOVECTOR_H
#define TABLE_ENGINE_LISTTOVECTOR_H

#include "engine.h"
#include "exception_collection.h"

template <typename T_>
class ListToVector {
   public:
    typedef T_ native_type;

    ListToVector() {
        py::converter::registry::push_back(
            &ListToVector<native_type>::convertible,
            &ListToVector<native_type>::construct, py::type_id<native_type>());
        py::to_python_converter<native_type, ListToVector<native_type>>();
    }

    static void *convertible(PyObject *py_object) {
        if (!PySequence_Check(py_object)) return nullptr;
        return py_object;
    }

    static void construct(PyObject *pyo,
                          py::converter::rvalue_from_python_stage1_data *data) {
        //! Placing an object in allocated memory (Replaced New)
        native_type *storage = new (
            reinterpret_cast<
                py::converter::rvalue_from_python_storage<native_type> *>(data)
                ->storage.bytes) native_type();
        fillVectorFromList(pyo, storage);
        data->convertible = storage;
    }

    static void fillVectorFromList(PyObject *py_object,
                                   native_type *const storage) {
        for (py::ssize_t i = 0, l = PySequence_Size(py_object); i < l; ++i) {
            typedef typename boost::range_value<native_type>::type
                containerValueType;

            py::extract<std::string> pyString(PySequence_GetItem(py_object, i));
            py::extract<containerValueType> pyObject(
                PySequence_GetItem(py_object, i));

            if (pyObject.check()) {
                storage->push_back(pyObject());
            } else if (pyString.check()) {
                try {
                    //! For double value if type = str
                    if (pyString.check() &&
                        (std::all_of(pyString().begin(), pyString().end(),
                                     ::isdigit)))
                        storage->push_back(
                            boost::lexical_cast<containerValueType>(
                                pyString()));
                } catch (boost::bad_lexical_cast &) {
                    BOOST_LOG_TRIVIAL(warning) << "Bad lexical cast";
                }
            }
        }
    }

    static PyObject *convert(const native_type &native_list) {
        try {
            py::list py_list;

            BOOST_FOREACH (auto value, native_list) { py_list.append(value); }

            return py::incref(py_list.ptr());
        } catch (std::exception e) {
            throw ConverterException(e.what());
        }
    }
};

#endif  // TABLE_ENGINE_LISTTOVECTOR_H
