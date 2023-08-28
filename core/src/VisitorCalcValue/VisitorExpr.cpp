#include "VisitorCalcValue.h"

VisitorCalcValue::VisitorCalcValue(
    const std::map<unsigned int, std::string> &nameColumns,
    const std::map<unsigned int, DvType> &typeColumns,
    std::map<unsigned int, DynamicValue> &rowValues, const time_t curDatetime)
    : CalcValueVisitor(), _curDatetime(curDatetime), _rowValues(rowValues) {
    _columnsByName =
        swapPairs<unsigned int, std::string>(std::move(nameColumns));

    BOOST_FOREACH (auto &m_pair, typeColumns) {
        if (nameColumns.find(m_pair.first) != nameColumns.end()) {
            _typeColumnsByName[nameColumns.at(m_pair.first)] = m_pair.second;
        }
    }
}

antlrcpp::Any VisitorCalcValue::visitParse(
    CalcValueParser::ParseContext *context) {
    return visit(context->statement());
}

antlrcpp::Any VisitorCalcValue::visitStatement(
    CalcValueParser::StatementContext *context) {
    return visitChildren(context);
}

antlrcpp::Any VisitorCalcValue::visitExprListFunc(
    CalcValueParser::ExprListFuncContext *context) {
    auto param = visit(context->expr()).as<DynamicValue *>();

    std::vector<DynamicValue *> *returnValue = new std::vector<DynamicValue *>;
    returnValue->push_back(param);

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitParamExprListFunc(
    CalcValueParser::ParamExprListFuncContext *context) {
    auto params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    auto param = visit(context->expr()).as<DynamicValue *>();

    params->push_back(param);

    antlrcpp::Any res(params);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitMultiplicationExpr(
    CalcValueParser::MultiplicationExprContext *context) {
    //! Get values
    auto r_leftValue = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_rightValue = visit(context->expr()[1]).as<DynamicValue *>();

    cpp_dec_float_50 lvalue, rvalue;

    if (r_leftValue->type == DvType::TYPE_STRING) {
        auto str_leftValue_value =
            boost::any_cast<std::string>(r_leftValue->value);

        if (!is_str_float(str_leftValue_value)) {
            this->_throw_type_error(context->getText());
        }

        lvalue = boost::lexical_cast<cpp_dec_float_50>(str_leftValue_value);
    } else {
        lvalue = boost::any_cast<cpp_dec_float_50>(r_leftValue->value);
    }

    if (r_rightValue->type == DvType::TYPE_STRING) {
        auto str_rightftValue_value =
            boost::any_cast<std::string>(r_rightValue->value);

        if (!is_str_float(str_rightftValue_value)) {
            this->_throw_type_error(context->getText());
        }

        rvalue = boost::lexical_cast<cpp_dec_float_50>(str_rightftValue_value);
    } else {
        rvalue = boost::any_cast<cpp_dec_float_50>(r_rightValue->value);
    }

    //! Get type of operation
    std::string operation = context->op->getText();
    DynamicValue *returnValue = new DynamicValue;

    if (operation == "*") lvalue *= rvalue;
    if (operation == "/") lvalue /= rvalue;

    if (boost::math::isnan(lvalue) || boost::math::isinf(lvalue))
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        (*returnValue) = {DvType::TYPE_NUMBER, lvalue};

    delete r_leftValue;
    delete r_rightValue;

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitConditionExpr(
    CalcValueParser::ConditionExprContext *context) {
    auto r_leftValue = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_rightValue = visit(context->expr()[1]).as<DynamicValue *>();

    auto operation = context->op->getText();

    DynamicValue *returnValue = new DynamicValue;

    if (r_leftValue->type == DvType::TYPE_OTHER ||
        r_rightValue->type == DvType::TYPE_OTHER) {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    } else {
        cpp_dec_float_50 rvalue =
            cmp<DynamicValue>((*r_leftValue), (*r_rightValue), operation);

        (*returnValue) = {DvType::TYPE_BOOLEAN, rvalue};
    }

    delete r_leftValue;
    delete r_rightValue;

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitAtomExpr(
    CalcValueParser::AtomExprContext *context) {
    return visitChildren(context);
}

antlrcpp::Any VisitorCalcValue::visitAdditiveExpr(
    CalcValueParser::AdditiveExprContext *context) {
    //! Get values
    auto r_leftValue = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_rightValue = visit(context->expr()[1]).as<DynamicValue *>();

    cpp_dec_float_50 lvalue, rvalue;
    auto l_type = r_leftValue->type;
    auto r_type = r_rightValue->type;

    DynamicValue *returnValue = new DynamicValue;

    if (l_type == DvType::TYPE_OTHER || r_type == DvType::TYPE_OTHER) {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    } else {
        if (r_leftValue->type == DvType::TYPE_STRING) {
            auto str_leftValue_value =
                boost::any_cast<std::string>(r_leftValue->value);

            if (!is_str_float(str_leftValue_value)) {
                this->_throw_type_error(context->getText());
            }

            lvalue = boost::lexical_cast<cpp_dec_float_50>(str_leftValue_value);
        } else {
            lvalue = boost::any_cast<cpp_dec_float_50>(r_leftValue->value);
        }

        if (r_rightValue->type == DvType::TYPE_STRING) {
            auto str_rightftValue_value =
                boost::any_cast<std::string>(r_rightValue->value);

            if (!is_str_float(str_rightftValue_value)) {
                this->_throw_type_error(context->getText());
            }

            rvalue =
                boost::lexical_cast<cpp_dec_float_50>(str_rightftValue_value);
        } else {
            rvalue = boost::any_cast<cpp_dec_float_50>(r_rightValue->value);
        }

        //! Get type of operation
        std::string operation = context->op->getText();
        returnValue->type = DvType::TYPE_NUMBER;

        if (l_type == DvType::TYPE_DATETIME &&
            r_type == DvType::TYPE_DATETIME) {
            returnValue->type = DvType::TYPE_DATETIME;
        } else if (l_type == DvType::TYPE_DATE && r_type == DvType::TYPE_DATE) {
            returnValue->type = DvType::TYPE_DATE;
        } else if (l_type == DvType::TYPE_TIME && r_type == DvType::TYPE_TIME) {
            rvalue = difftime((time_t)rvalue, _initTime);
            returnValue->type = DvType::TYPE_TIME;
        } else if (l_type == DvType::TYPE_TIME && r_type == DvType::TYPE_DATE) {
            lvalue = difftime((time_t)lvalue, _initTime);
            returnValue->type = DvType::TYPE_DATETIME;
        } else if (l_type == DvType::TYPE_DATE && r_type == DvType::TYPE_TIME) {
            rvalue = difftime((time_t)rvalue, _initTime);
            returnValue->type = DvType::TYPE_DATETIME;
        } else if (l_type == DvType::TYPE_DATETIME ||
                   l_type == DvType::TYPE_TIME) {
            rvalue *= 86400;
            returnValue->type = DvType::TYPE_DATETIME;
        } else if (r_type == DvType::TYPE_DATETIME ||
                   r_type == DvType::TYPE_TIME) {
            lvalue *= 86400;
            returnValue->type = DvType::TYPE_DATETIME;
        } else if (l_type == DvType::TYPE_DATE) {
            rvalue *= 86400;
            returnValue->type = DvType::TYPE_DATE;

        } else if (r_type == DvType::TYPE_DATE) {
            lvalue *= 86400;
            returnValue->type = DvType::TYPE_DATE;
        }

        if (operation == "+") lvalue += rvalue;
        if (operation == "-") lvalue -= rvalue;

        returnValue->value = lvalue;
    }

    delete r_leftValue;
    delete r_rightValue;

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitTextAtom(
    CalcValueParser::TextAtomContext *context) {
    DynamicValue *returnValue = new DynamicValue;
    (*returnValue) = {DvType::TYPE_STRING,
                      context->getText() == "\"\"" ? "" : context->getText()};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitColumnAtom(
    CalcValueParser::ColumnAtomContext *context) {
    DynamicValue *returnValue = new DynamicValue;

    if (this->_columnsByName.find(context->getText()) ==
            this->_columnsByName.end() ||
        this->_rowValues.find(this->_columnsByName.at(context->getText())) ==
            this->_rowValues.end()) {
        (*returnValue) = {DvType::TYPE_NONE, cpp_dec_float_50(0)};
    } else {
        auto value =
            this->_rowValues.at(this->_columnsByName.at(context->getText()));

        if (this->_typeColumnsByName.find(context->getText()) !=
            this->_typeColumnsByName.end()) {
            auto type = this->_typeColumnsByName.at(context->getText());
            to_type(type, value);
        }

        (*returnValue) = value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitNumberAtom(
    CalcValueParser::NumberAtomContext *context) {
    DynamicValue *returnValue = new DynamicValue;
    cpp_dec_float_50 value(context->getText());
    (*returnValue) = {DvType::TYPE_NUMBER, value};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitParExpr(
    CalcValueParser::ParExprContext *context) {
    return visit(context->expr());
}

antlrcpp::Any VisitorCalcValue::visitBooleanAtom(
    CalcValueParser::BooleanAtomContext *context) {
    DynamicValue *returnValue = new DynamicValue;
    cpp_dec_float_50 value;

    value = static_cast<int>(context->FALSE() == NULL);

    (*returnValue) = {DvType::TYPE_BOOLEAN, value};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitNoneExpr(
    CalcValueParser::NoneExprContext *context) {
    DynamicValue *returnValue = new DynamicValue;

    (*returnValue) = {DvType::TYPE_NONE, cpp_dec_float_50(0)};

    antlrcpp::Any res(returnValue);
    return res;
}

void VisitorCalcValue::_throw_type_error(const std::string &expression) {
    std::string msg =
        "Expression \"%s\"  cannot be executed due to type mismatch";
    throw FormulaException((boost::format(msg) % expression).str());
}