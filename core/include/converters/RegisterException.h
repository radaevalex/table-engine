#ifndef TABLE_ENGINE_REGISTEREXCEPTION_H
#define TABLE_ENGINE_REGISTEREXCEPTION_H

#include "engine.h"

template <typename CPPException>
class RegisterException {
   public:
    RegisterException(std::string namePyException,
                      PyObject* basePyException = PyExc_Exception) {
        std::string scopeName =
            py::extract<std::string>(py::scope().attr("__name__"));
        std::string qualifiedName = scopeName + "." + namePyException;

        PyObject* pyException =
            PyErr_NewException(qualifiedName.c_str(), basePyException, nullptr);

        if (!pyException) py::throw_error_already_set();

        py::scope().attr(namePyException.c_str()) =
            py::handle<>(py::borrowed(pyException));

        py::register_exception_translator<CPPException>(
            [pyException](CPPException const& exc) {
                PyErr_SetString(pyException, exc.what());
            });

        this->pyException = pyException;
    }

    PyObject* getPyException() { return pyException; }

   private:
    PyObject* pyException;
};

#endif  // TABLE_ENGINE_REGISTEREXCEPTION_H
