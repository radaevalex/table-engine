#include "VisitorCalcValue.h"

antlrcpp::Any VisitorCalcValue::visitFuncDateTime(
    CalcValueParser::FuncDateTimeContext *context) {
    return visitChildren(context);
}

antlrcpp::Any VisitorCalcValue::visitDateFunc(
    CalcValueParser::DateFuncContext *context) {
    DynamicValue *returnValue = new DynamicValue;

    auto r_year = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_month = visit(context->expr()[1]).as<DynamicValue *>();
    auto r_day = visit(context->expr()[2]).as<DynamicValue *>();

    auto year_type = r_year->type;
    auto month_type = r_month->type;
    auto day_type = r_day->type;
    std::tm tdate = {};

    if (year_type == DvType::TYPE_OTHER || month_type == DvType::TYPE_OTHER ||
        day_type == DvType::TYPE_OTHER) {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    } else {
        if (year_type == DvType::TYPE_STRING) {
            auto str_year = boost::any_cast<std::string>(r_year->value);

            if (!is_str_float(str_year)) {
                this->_throw_type_error(context->getText());
            }
            tdate.tm_year = boost::lexical_cast<int>(str_year);
        } else {
            tdate.tm_year =
                (int)boost::any_cast<cpp_dec_float_50>(r_year->value);
        }

        if (month_type == DvType::TYPE_STRING) {
            auto str_month = boost::any_cast<std::string>(r_month->value);

            if (!is_str_float(str_month)) {
                this->_throw_type_error(context->getText());
            }
            tdate.tm_mon = boost::lexical_cast<int>(str_month);
        } else {
            tdate.tm_mon =
                (int)boost::any_cast<cpp_dec_float_50>(r_month->value);
        }

        if (month_type == DvType::TYPE_STRING) {
            auto str_day = boost::any_cast<std::string>(r_day->value);

            if (!is_str_float(str_day)) {
                this->_throw_type_error(context->getText());
            }
            tdate.tm_mday = boost::lexical_cast<int>(str_day);
        } else {
            tdate.tm_mday =
                (int)boost::any_cast<cpp_dec_float_50>(r_day->value);
        }

        tdate.tm_year -= 1900;
        tdate.tm_mon -= 1;
        (*returnValue) = {DvType::TYPE_DATE,
                          static_cast<cpp_dec_float_50>(timelocal(&tdate))};
    }

    delete r_year;
    delete r_month;
    delete r_day;

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitTimeFunc(
    CalcValueParser::TimeFuncContext *context) {
    DynamicValue *returnValue = new DynamicValue;

    auto r_hour = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_minute = visit(context->expr()[1]).as<DynamicValue *>();
    auto r_second = visit(context->expr()[2]).as<DynamicValue *>();

    auto hour_type = r_hour->type;
    auto minute_type = r_minute->type;
    auto second_type = r_second->type;
    int hour_value, minute_value, second_value;

    if (hour_type == DvType::TYPE_OTHER || minute_type == DvType::TYPE_OTHER ||
        second_type == DvType::TYPE_OTHER) {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    } else {
        if (hour_type == DvType::TYPE_STRING) {
            auto str_hour = boost::any_cast<std::string>(r_hour->value);

            if (!is_str_float(str_hour)) {
                this->_throw_type_error(context->getText());
            }
            hour_value = boost::lexical_cast<int>(str_hour);
        } else {
            hour_value = (int)boost::any_cast<cpp_dec_float_50>(r_hour->value);
        }

        if (minute_type == DvType::TYPE_STRING) {
            auto str_minute = boost::any_cast<std::string>(r_minute->value);

            if (!is_str_float(str_minute)) {
                this->_throw_type_error(context->getText());
            }
            minute_value = boost::lexical_cast<int>(str_minute);
        } else {
            minute_value =
                (int)boost::any_cast<cpp_dec_float_50>(r_minute->value);
        }

        if (minute_type == DvType::TYPE_STRING) {
            auto str_second = boost::any_cast<std::string>(r_second->value);

            if (!is_str_float(str_second)) {
                this->_throw_type_error(context->getText());
            }
            second_value = boost::lexical_cast<int>(str_second);
        } else {
            second_value =
                (int)boost::any_cast<cpp_dec_float_50>(r_second->value);
        }

        std::tm tdate = {second_value, minute_value, hour_value, 1, 0, 70};

        (*returnValue) = {DvType::TYPE_TIME,
                          cpp_dec_float_50(timelocal(&tdate))};
    }

    delete r_hour;
    delete r_minute;
    delete r_second;

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitYearFunc(
    CalcValueParser::YearFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();
    time_t date_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;
        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);

        cpp_dec_float_50 value(tdate->tm_year + 1900);

        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitMonthFunc(
    CalcValueParser::MonthFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();
    time_t date_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;

        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);
        cpp_dec_float_50 value(tdate->tm_mon + 1);
        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitDayFunc(
    CalcValueParser::DayFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();
    time_t date_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;

        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);
        cpp_dec_float_50 value(tdate->tm_mday);
        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitHourFunc(
    CalcValueParser::HourFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();
    time_t date_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;

        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);
        cpp_dec_float_50 value(tdate->tm_hour);
        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitMinuteFunc(
    CalcValueParser::MinuteFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();
    time_t date_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;

        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);
        cpp_dec_float_50 value(tdate->tm_min);
        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitSecondFunc(
    CalcValueParser::SecondFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();
    time_t date_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;

        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);
        cpp_dec_float_50 value(tdate->tm_sec);
        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitNowFunc(
    CalcValueParser::NowFuncContext *context) {
    DynamicValue *returnValue = new DynamicValue;

    (*returnValue) = {DvType::TYPE_DATETIME,
                      static_cast<cpp_dec_float_50>(_curDatetime)};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitTodayFunc(
    CalcValueParser::TodayFuncContext *context) {
    DynamicValue *returnValue = new DynamicValue;
    auto tdate = std::localtime(&_curDatetime);

    tdate->tm_sec = 0;
    tdate->tm_min = 0;
    tdate->tm_hour = 0;

    (*returnValue) = {DvType::TYPE_DATE,
                      static_cast<cpp_dec_float_50>(std::mktime(tdate))};

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitWeekdayFunc(
    CalcValueParser::WeekdayFuncContext *context) {
    DynamicValue *returnValue;

    auto r_value = visit(context->expr()).as<DynamicValue *>();

    time_t date_value;
    int type_value;

    if (r_value->type == DvType::TYPE_OTHER) {
        returnValue = r_value;
    } else {
        returnValue = new DynamicValue;

        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        auto tdate = std::localtime(&date_value);

        cpp_dec_float_50 value(
            (tdate->tm_wday + 1) == 7 ? 7 : (tdate->tm_wday + 1) % 7);

        (*returnValue) = {DvType::TYPE_NUMBER, value};

        delete r_value;
    }

    antlrcpp::Any res(returnValue);
    return res;
}

antlrcpp::Any VisitorCalcValue::visitWeekdayWithTypeFunc(
    CalcValueParser::WeekdayWithTypeFuncContext *context) {
    DynamicValue *returnValue = new DynamicValue;

    auto r_value = visit(context->expr()[0]).as<DynamicValue *>();
    auto r_type = visit(context->expr()[1]).as<DynamicValue *>();

    time_t date_value;
    int type_value;

    if (r_value->type == DvType::TYPE_OTHER ||
        r_type->type == DvType::TYPE_OTHER) {
        (*returnValue) = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    } else {
        if (r_value->type == DvType::TYPE_STRING) {
            auto str_value = boost::any_cast<std::string>(r_value->value);

            if (!is_str_float(str_value)) {
                this->_throw_type_error(context->getText());
            }
            date_value = boost::lexical_cast<int>(str_value);
        } else {
            date_value = (int)boost::any_cast<cpp_dec_float_50>(r_value->value);
        }

        if (r_type->type == DvType::TYPE_STRING) {
            auto str_type = boost::any_cast<std::string>(r_type->value);

            if (!is_str_int(str_type)) {
                this->_throw_type_error(context->getText());
            }
            type_value = boost::lexical_cast<int>(str_type);
        } else {
            type_value = (int)boost::any_cast<cpp_dec_float_50>(r_type->value);
        }

        auto tdate = std::localtime(&date_value);

        cpp_dec_float_50 value;

        auto type = DvType::TYPE_NUMBER;

        if (type_value == 1 || type_value == 17) {
            value = (tdate->tm_wday + 1) == 7 ? 7 : (tdate->tm_wday + 1) % 7;
        } else if (type_value == 2) {
            value = tdate->tm_wday;
        } else if (type_value == 3 || type_value == 11) {
            value = tdate->tm_wday - 1;
        } else if (type_value == 12) {
            value = (tdate->tm_wday + 6) == 7 ? 7 : (tdate->tm_wday + 6) % 7;
        } else if (type_value == 13) {
            value = (tdate->tm_wday + 5) == 7 ? 7 : (tdate->tm_wday + 5) % 7;
        } else if (type_value == 14) {
            value = (tdate->tm_wday + 4) == 7 ? 7 : (tdate->tm_wday + 4) % 7;
        } else if (type_value == 15) {
            value = (tdate->tm_wday + 3) == 7 ? 7 : (tdate->tm_wday + 3) % 7;
        } else if (type_value == 16) {
            value = (tdate->tm_wday + 2) == 7 ? 7 : (tdate->tm_wday + 2) % 7;
        } else {
            value = cpp_dec_float_50(NAN);
            type = DvType::TYPE_OTHER;
        }

        (*returnValue) = {type, value};
    }

    delete r_value;
    delete r_type;

    antlrcpp::Any res(returnValue);
    return res;
}
