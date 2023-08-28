#include "VisitorCalcValue.h"

antlrcpp::Any VisitorCalcValue::visitFuncLogical(
    CalcValueParser::FuncLogicalContext *context) {
    return visitChildren(context);
}

antlrcpp::Any VisitorCalcValue::visitNotFunc(
    CalcValueParser::NotFuncContext *context) {
    auto r_condition = visit(context->expr()).as<DynamicValue *>();

    DynamicValue *returnValue;

    if (r_condition->type == DvType::TYPE_OTHER) {
        returnValue = r_condition;
    } else {
        returnValue = new DynamicValue;
        cpp_dec_float_50 condition_value;
        cpp_dec_float_50 rvalue(1);

        if (r_condition->type == DvType::TYPE_STRING) {
            auto str_elem_value =
                boost::any_cast<std::string>(r_condition->value);

            if (!is_str_float(str_elem_value)) {
                this->_throw_type_error(context->getText());
            }

            condition_value =
                boost::lexical_cast<cpp_dec_float_50>(str_elem_value);
        } else {
            condition_value =
                boost::any_cast<cpp_dec_float_50>(r_condition->value);
        }

        delete r_condition;

        if (condition_value) rvalue = 0;

        (*returnValue) = {DvType::TYPE_BOOLEAN, rvalue};
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitAndFunc(
    CalcValueParser::AndFuncContext *context) {
    auto r_conditions =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();

    DynamicValue *returnValue = new DynamicValue;
    cpp_dec_float_50 rvalue(1);

    BOOST_FOREACH (auto &elem, (*r_conditions)) {
        if (elem->type == DvType::TYPE_NONE || elem->type == DvType::TYPE_OTHER)
            rvalue = cpp_dec_float_50(NAN);

        if (!boost::math::isnan(rvalue)) {
            cpp_dec_float_50 elem_value;

            if (elem->type == DvType::TYPE_STRING) {
                auto str_elem_value = boost::any_cast<std::string>(elem->value);

                if (!is_str_float(str_elem_value)) {
                    this->_throw_type_error(context->getText());
                }

                elem_value =
                    boost::lexical_cast<cpp_dec_float_50>(str_elem_value);
            } else {
                elem_value = boost::any_cast<cpp_dec_float_50>(elem->value);
            }

            if (!elem_value) rvalue = 0;
        }

        delete elem;
    }

    delete r_conditions;

    auto type =
        boost::math::isnan(rvalue) ? DvType::TYPE_OTHER : DvType::TYPE_BOOLEAN;

    (*returnValue) = {type, rvalue};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitOrFunc(
    CalcValueParser::OrFuncContext *context) {
    auto r_conditions =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();

    DynamicValue *returnValue = new DynamicValue;
    cpp_dec_float_50 rvalue(0);

    BOOST_FOREACH (auto &elem, (*r_conditions)) {
        if (elem->type == DvType::TYPE_NONE || elem->type == DvType::TYPE_OTHER)
            rvalue = cpp_dec_float_50(NAN);

        if (!boost::math::isnan(rvalue)) {
            cpp_dec_float_50 elem_value;

            if (elem->type == DvType::TYPE_STRING) {
                auto str_elem_value = boost::any_cast<std::string>(elem->value);

                if (!is_str_float(str_elem_value)) {
                    this->_throw_type_error(context->getText());
                }

                elem_value =
                    boost::lexical_cast<cpp_dec_float_50>(str_elem_value);
            } else {
                elem_value = boost::any_cast<cpp_dec_float_50>(elem->value);
            }

            if (elem_value) rvalue = 1;
        }

        delete elem;
    }

    delete r_conditions;

    auto type =
        boost::math::isnan(rvalue) ? DvType::TYPE_OTHER : DvType::TYPE_BOOLEAN;

    (*returnValue) = {type, rvalue};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitIfFunc(
    CalcValueParser::IfFuncContext *context) {
    auto r_condition_value = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_left_value = visit(context->expr()[1]).as<DynamicValue *>();
    auto r_right_value = visit(context->expr()[2]).as<DynamicValue *>();
    DynamicValue *returnValue;

    cpp_dec_float_50 condition_value;
    if (r_condition_value->type == DvType::TYPE_OTHER) {
        returnValue = new DynamicValue;
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};

        delete r_left_value;
        delete r_right_value;
    } else {
        if (r_condition_value->type == DvType::TYPE_STRING) {
            auto str_condition_value =
                boost::any_cast<std::string>(r_condition_value->value);

            if (!is_str_int(str_condition_value)) {
                this->_throw_type_error(context->getText());
            }

            condition_value =
                boost::lexical_cast<cpp_dec_float_50>(str_condition_value);
        } else {
            condition_value =
                boost::any_cast<cpp_dec_float_50>(r_condition_value->value);
        }

        if (!condition_value) {
            returnValue = r_right_value;
            delete r_left_value;
        } else {
            returnValue = r_left_value;
            delete r_right_value;
        }
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitIfsFunc(
    CalcValueParser::IfsFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();

    DynamicValue *returnValue = new DynamicValue;
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    int index_value = NULL;

    for (int index = 0; index < (*r_params).size(); index++) {
        if (isOther || (index_value == NULL && !(index % 2))) {
            cpp_dec_float_50 condition_value(0);

            if ((*r_params)[index]->type == DvType::TYPE_STRING) {
                auto str_condition_value =
                    boost::any_cast<std::string>((*r_params)[index]->value);

                if (!is_str_int(str_condition_value)) {
                    this->_throw_type_error(context->getText());
                }

                condition_value =
                    boost::lexical_cast<cpp_dec_float_50>(str_condition_value);
            } else {
                condition_value = boost::any_cast<cpp_dec_float_50>(
                    (*r_params)[index]->value);
            }

            if (condition_value) {
                index_value = index + 1;
            }
        }

        if (index_value != index) delete (*r_params)[index];
    }

    if (index_value != NULL && index_value < (*r_params).size()) {
        returnValue = (*r_params)[index_value];
    } else {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    }

    delete r_params;

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitSwitchFunc(
    CalcValueParser::SwitchFuncContext *context) {
    auto r_expession = visit(context->expr()).as<DynamicValue *>();
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    std::string str_expession_value;
    DynamicValue *returnValue;
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    if (r_expession->type == DvType::TYPE_OTHER) {
        str_expession_value = "";
        isOther = true;
        returnValue = new DynamicValue;
    } else if (r_expession->type == DvType::TYPE_NONE) {
        str_expession_value = "";
    } else if (r_expession->type != DvType::TYPE_STRING) {
        str_expession_value = boost::lexical_cast<std::string>(
            boost::any_cast<cpp_dec_float_50>(r_expession->value));
    } else {
        str_expession_value = boost::any_cast<std::string>(r_expession->value);
    }

    int index_value = NULL;

    for (int index = 0; index < (*r_params).size(); index++) {
        if (isOther || (index_value == NULL && !(index % 2))) {
            std::string str_elem_value;

            if ((*r_params)[index]->type == DvType::TYPE_NONE) {
                str_elem_value = "";
            } else if ((*r_params)[index]->type != DvType::TYPE_STRING) {
                str_elem_value = boost::lexical_cast<std::string>(
                    boost::any_cast<cpp_dec_float_50>(
                        (*r_params)[index]->value));
            } else {
                str_elem_value =
                    boost::any_cast<std::string>((*r_params)[index]->value);
            }

            if (str_elem_value == str_expession_value) {
                index_value = index + 1;
            } else if (index == ((*r_params).size() - 1)) {
                index_value = index;
            }
        }
        if (index_value != index) delete (*r_params)[index];
    }

    if (index_value == NULL) {
        auto msg = "Value not found in function %s";

        throw FormulaException((boost::format(msg) % context->getText()).str());
    }

    if (isOther)
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        returnValue = (*r_params)[index_value];

    delete r_expession;
    delete r_params;

    antlrcpp::Any res(returnValue);
    return res;
}
