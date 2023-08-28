#include "VisitorCalcValue.h"

antlrcpp::Any VisitorCalcValue::visitFuncExpr(
    CalcValueParser::FuncExprContext *context) {
    return visitChildren(context);
}

antlrcpp::Any VisitorCalcValue::visitSumFunc(
    CalcValueParser::SumFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    DynamicValue *returnValue = new DynamicValue;

    cpp_dec_float_50 value(0);
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    BOOST_FOREACH (auto &elem, (*r_params)) {
        cpp_dec_float_50 elem_value;

        if (elem->type == DvType::TYPE_OTHER) {
            isOther = true;
        } else {
            if (elem->type == DvType::TYPE_STRING) {
                auto str_year = boost::any_cast<std::string>(elem->value);

                if (!is_str_float(str_year)) {
                    this->_throw_type_error(context->getText());
                }
                elem_value = boost::lexical_cast<cpp_dec_float_50>(str_year);

            } else {
                elem_value = boost::any_cast<cpp_dec_float_50>(elem->value);
            }

            value += elem_value;
        }

        delete elem;
    }

    delete r_params;

    if (isOther)
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        (*returnValue) = {DvType::TYPE_NUMBER, value};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitAverageFunc(
    CalcValueParser::AverageFuncContext *context) {
    auto r_value = visitSumFunc((CalcValueParser::SumFuncContext *)context)
                       .as<DynamicValue *>();
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();

    if (r_value->type != DvType::TYPE_OTHER) {
        auto value = boost::any_cast<cpp_dec_float_50>(r_value->value);
        r_value->value = cpp_dec_float_50(value / r_params->size());
    }

    BOOST_FOREACH (auto &elem, (*r_params)) { delete elem; }

    delete r_params;

    return r_value;
}

antlrcpp::Any VisitorCalcValue::visitMedianFunc(
    CalcValueParser::MedianFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    DynamicValue *returnValue = new DynamicValue;

    std::vector<cpp_dec_float_50> values;
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    BOOST_FOREACH (auto &elem, (*r_params)) {
        cpp_dec_float_50 elem_value;

        if (elem->type == DvType::TYPE_OTHER) {
            isOther = true;
        } else {
            if (elem->type == DvType::TYPE_STRING) {
                auto str_year = boost::any_cast<std::string>(elem->value);

                if (!is_str_float(str_year)) {
                    this->_throw_type_error(context->getText());
                }
                elem_value = boost::lexical_cast<cpp_dec_float_50>(str_year);

            } else {
                elem_value = boost::any_cast<cpp_dec_float_50>(elem->value);
            }

            values.push_back(elem_value);
        }

        delete elem;
    }

    delete r_params;

    if (isOther) {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    } else {
        boost::range::sort(values);

        if (values.size() % 2) {
            (*returnValue) = {DvType::TYPE_NUMBER,
                              values[static_cast<int>(values.size() / 2)]};
        } else {
            auto elem1 = values[static_cast<int>(values.size() / 2) - 1];
            auto elem2 = values[static_cast<int>(values.size() / 2)];

            (*returnValue) = {
                DvType::TYPE_NUMBER,
                boost::lexical_cast<cpp_dec_float_50>((elem1 + elem2) / 2)};
        }
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitMinFunc(
    CalcValueParser::MinFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();

    DynamicValue *returnValue = new DynamicValue;

    cpp_dec_float_50 minValue(INFINITY);
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    if (!r_params->size()) {
        this->_throw_type_error(context->getText());
    }

    BOOST_FOREACH (auto &elem, (*r_params)) {
        if (elem->type == DvType::TYPE_OTHER) {
            isOther = true;
        } else {
            cpp_dec_float_50 elem_value;

            if (elem->type == DvType::TYPE_STRING) {
                auto str_year = boost::any_cast<std::string>(elem->value);

                if (!is_str_float(str_year)) {
                    this->_throw_type_error(context->getText());
                }
                elem_value = boost::lexical_cast<cpp_dec_float_50>(str_year);

            } else {
                elem_value = boost::any_cast<cpp_dec_float_50>(elem->value);
            }

            if (minValue > elem_value) {
                minValue = elem_value;
            }
        }

        delete elem;
    }

    if (isOther)
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        (*returnValue) = {DvType::TYPE_NUMBER, minValue};

    delete r_params;

    return returnValue;
}

antlrcpp::Any VisitorCalcValue::visitMaxFunc(
    CalcValueParser::MaxFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();

    DynamicValue *returnValue = new DynamicValue;

    cpp_dec_float_50 minValue(-INFINITY);
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    if (!r_params->size()) {
        this->_throw_type_error(context->getText());
    }

    BOOST_FOREACH (auto &elem, (*r_params)) {
        if (elem->type == DvType::TYPE_OTHER) {
            isOther = true;
        } else {
            cpp_dec_float_50 elem_value;

            if (elem->type == DvType::TYPE_STRING) {
                auto str_year = boost::any_cast<std::string>(elem->value);

                if (!is_str_float(str_year)) {
                    this->_throw_type_error(context->getText());
                }
                elem_value = boost::lexical_cast<cpp_dec_float_50>(str_year);

            } else {
                elem_value = boost::any_cast<cpp_dec_float_50>(elem->value);
            }

            if (minValue < elem_value) {
                minValue = elem_value;
            }
        }

        delete elem;
    }

    if (isOther)
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        (*returnValue) = {DvType::TYPE_NUMBER, minValue};

    delete r_params;

    return returnValue;
}

antlrcpp::Any VisitorCalcValue::visitCountFunc(
    CalcValueParser::CountFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    DynamicValue *returnValue = new DynamicValue;
    cpp_dec_float_50 value(0);

    BOOST_FOREACH (auto &elem, (*r_params)) {
        delete elem;

        if (elem->type == DvType::TYPE_NONE || elem->type == DvType::TYPE_OTHER)
            continue;

        value++;
    }

    delete r_params;

    (*returnValue) = {DvType::TYPE_NUMBER,
                      static_cast<cpp_dec_float_50>(value)};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitConcatFunc(
    CalcValueParser::ConcatFuncContext *context) {
    auto r_params =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    DynamicValue *returnValue = new DynamicValue;
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other
    std::string rvalue = "";

    BOOST_FOREACH (auto &elem, (*r_params)) {
        if (elem->type == DvType::TYPE_OTHER) {
            isOther = true;
        } else {
            if (elem->type == DvType::TYPE_NONE) {
                rvalue += "";
            } else if (elem->type != DvType::TYPE_STRING) {
                rvalue += boost::lexical_cast<std::string>(
                    boost::any_cast<cpp_dec_float_50>(elem->value));
            } else {
                rvalue += boost::any_cast<std::string>(elem->value);
            }
        }

        delete elem;
    }

    delete r_params;

    if (isOther)
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        (*returnValue) = {DvType::TYPE_STRING, rvalue};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitTextjoinFunc(
    CalcValueParser::TextjoinFuncContext *context) {
    auto r_values =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    auto r_connector = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_skip_empty = visit(context->expr()[1]).as<DynamicValue *>();

    DynamicValue *returnValue = new DynamicValue;

    std::string connector;
    bool skip_empty;
    std::string rvalue = "";
    bool isOther = false;  //! if one of the value type is other then the
                           //! resulting value type is other

    if (r_connector->type == DvType::TYPE_OTHER) {
        isOther = true;
    }
    if (r_connector->type == DvType::TYPE_NONE) {
        connector = "";
    } else if (r_connector->type != DvType::TYPE_STRING) {
        connector = boost::lexical_cast<std::string>(
            boost::any_cast<cpp_dec_float_50>(r_connector->value));
    } else {
        connector = boost::any_cast<std::string>(r_connector->value);
    }

    if (r_skip_empty->type == DvType::TYPE_OTHER) {
        isOther = true;
    } else if (r_skip_empty->type == DvType::TYPE_STRING) {
        auto str_value = boost::any_cast<std::string>(r_skip_empty->value);

        if (!is_str_float(str_value)) {
            this->_throw_type_error(context->getText());
        }

        skip_empty =
            static_cast<bool>(boost::lexical_cast<cpp_dec_float_50>(str_value));
    } else {
        skip_empty = static_cast<bool>(
            boost::any_cast<cpp_dec_float_50>(r_skip_empty->value));
    }

    BOOST_FOREACH (auto &elem, (*r_values)) {
        if (elem->type == DvType::TYPE_OTHER) isOther = true;

        if (!isOther) {
            std::string str_value;

            if (elem->type == DvType::TYPE_NONE) {
                str_value = "";
            } else if (elem->type != DvType::TYPE_STRING) {
                str_value = boost::lexical_cast<std::string>(
                    boost::any_cast<cpp_dec_float_50>(elem->value));
            } else {
                str_value = boost::any_cast<std::string>(elem->value);
            }

            if (skip_empty && !str_value.size()) {
                delete elem;
                continue;
            }

            if (rvalue.size()) {
                rvalue += connector;
            }

            rvalue += str_value;
        }

        delete elem;
    }

    delete r_values;
    delete r_connector;
    delete r_skip_empty;

    if (isOther)
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    else
        (*returnValue) = {DvType::TYPE_STRING, rvalue};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitChooseFunc(
    CalcValueParser::ChooseFuncContext *context) {
    auto r_index = visit(context->expr()).as<DynamicValue *>();
    auto r_values =
        visit(context->paramsExprList()).as<std::vector<DynamicValue *> *>();
    DynamicValue *returnValue;

    int index_value;

    if (r_index->type == DvType::TYPE_STRING) {
        auto str_index_value = boost::any_cast<std::string>(r_index->value);

        if (!is_str_float(str_index_value)) {
            this->_throw_type_error(context->getText());
        }

        index_value = boost::lexical_cast<int>(
            boost::lexical_cast<cpp_dec_float_50>(str_index_value));
    } else {
        index_value = boost::lexical_cast<int>(
            boost::any_cast<cpp_dec_float_50>(r_index->value));
    }

    if (index_value > r_values->size() && index_value < 1) {
        auto msg = "In function %s index value does not match index values";

        throw FormulaException((boost::format(msg) % context->getText()).str());
    }

    returnValue = (*r_values)[index_value - 1];

    for (int index = 0; index < (*r_values).size(); index++) {
        if (index != index_value - 1) delete (*r_values)[index];
    }

    delete r_values;
    delete r_index;

    antlrcpp::Any res(returnValue);
    return res;
}
