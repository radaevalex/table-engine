#ifndef TABLE_ENGINE_EXCEPTIONS_H
#define TABLE_ENGINE_EXCEPTIONS_H

#include "engine.h"

class EngineException : public std::exception {
public:
    EngineException(std::string msg) {
        if (msg.find(PRE_M_ERROR) == -1) {
            this->m_error = this->PRE_M_ERROR + msg;
        } else {
            this->m_error = msg;
        }
    }

    const char *what() const noexcept {
        return this->m_error.c_str();
    }

protected:
    std::string m_error = "";
    std::string PRE_M_ERROR = "ERROR: ";
};

class FormulaException : public EngineException {
public:
    FormulaException(std::string msg) : EngineException(msg) {
        if (msg.find(PRE_M_ERROR) == -1) {
            this->m_error = this->PRE_M_ERROR + msg;
        } else {
            this->m_error = msg;
        }
    }

    const char *what() const noexcept {
        return this->m_error.c_str();
    }

protected:
    std::string PRE_M_ERROR = "Formula calculation ERROR: ";
};


class ConverterException : public EngineException {
public:
    ConverterException(std::string msg) : EngineException(msg) {
        if (msg.find(PRE_M_ERROR) == -1) {
            this->m_error = this->PRE_M_ERROR + msg;
        } else {
            this->m_error = msg;
        }
    }

    const char *what() const noexcept {
        return this->m_error.c_str();
    }

protected:
    std::string PRE_M_ERROR = "Converting object ERROR: ";
};

#endif //TABLE_ENGINE_EXCEPTIONS_H
