
// Generated from CalcValue.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CalcValueParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalcValueParser.
 */
class  CalcValueVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalcValueParser.
   */
    virtual antlrcpp::Any visitParse(CalcValueParser::ParseContext *context) = 0;

    virtual antlrcpp::Any visitStatement(CalcValueParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitSumFunc(CalcValueParser::SumFuncContext *context) = 0;

    virtual antlrcpp::Any visitAverageFunc(CalcValueParser::AverageFuncContext *context) = 0;

    virtual antlrcpp::Any visitMedianFunc(CalcValueParser::MedianFuncContext *context) = 0;

    virtual antlrcpp::Any visitMinFunc(CalcValueParser::MinFuncContext *context) = 0;

    virtual antlrcpp::Any visitMaxFunc(CalcValueParser::MaxFuncContext *context) = 0;

    virtual antlrcpp::Any visitConcatFunc(CalcValueParser::ConcatFuncContext *context) = 0;

    virtual antlrcpp::Any visitCountFunc(CalcValueParser::CountFuncContext *context) = 0;

    virtual antlrcpp::Any visitTextjoinFunc(CalcValueParser::TextjoinFuncContext *context) = 0;

    virtual antlrcpp::Any visitChooseFunc(CalcValueParser::ChooseFuncContext *context) = 0;

    virtual antlrcpp::Any visitIfFunc(CalcValueParser::IfFuncContext *context) = 0;

    virtual antlrcpp::Any visitIfsFunc(CalcValueParser::IfsFuncContext *context) = 0;

    virtual antlrcpp::Any visitSwitchFunc(CalcValueParser::SwitchFuncContext *context) = 0;

    virtual antlrcpp::Any visitNotFunc(CalcValueParser::NotFuncContext *context) = 0;

    virtual antlrcpp::Any visitAndFunc(CalcValueParser::AndFuncContext *context) = 0;

    virtual antlrcpp::Any visitOrFunc(CalcValueParser::OrFuncContext *context) = 0;

    virtual antlrcpp::Any visitDateFunc(CalcValueParser::DateFuncContext *context) = 0;

    virtual antlrcpp::Any visitTimeFunc(CalcValueParser::TimeFuncContext *context) = 0;

    virtual antlrcpp::Any visitYearFunc(CalcValueParser::YearFuncContext *context) = 0;

    virtual antlrcpp::Any visitMonthFunc(CalcValueParser::MonthFuncContext *context) = 0;

    virtual antlrcpp::Any visitDayFunc(CalcValueParser::DayFuncContext *context) = 0;

    virtual antlrcpp::Any visitHourFunc(CalcValueParser::HourFuncContext *context) = 0;

    virtual antlrcpp::Any visitMinuteFunc(CalcValueParser::MinuteFuncContext *context) = 0;

    virtual antlrcpp::Any visitSecondFunc(CalcValueParser::SecondFuncContext *context) = 0;

    virtual antlrcpp::Any visitNowFunc(CalcValueParser::NowFuncContext *context) = 0;

    virtual antlrcpp::Any visitTodayFunc(CalcValueParser::TodayFuncContext *context) = 0;

    virtual antlrcpp::Any visitWeekdayFunc(CalcValueParser::WeekdayFuncContext *context) = 0;

    virtual antlrcpp::Any visitWeekdayWithTypeFunc(CalcValueParser::WeekdayWithTypeFuncContext *context) = 0;

    virtual antlrcpp::Any visitExprListFunc(CalcValueParser::ExprListFuncContext *context) = 0;

    virtual antlrcpp::Any visitParamExprListFunc(CalcValueParser::ParamExprListFuncContext *context) = 0;

    virtual antlrcpp::Any visitFuncExpr(CalcValueParser::FuncExprContext *context) = 0;

    virtual antlrcpp::Any visitFuncDateTime(CalcValueParser::FuncDateTimeContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicationExpr(CalcValueParser::MultiplicationExprContext *context) = 0;

    virtual antlrcpp::Any visitConditionExpr(CalcValueParser::ConditionExprContext *context) = 0;

    virtual antlrcpp::Any visitFuncLogical(CalcValueParser::FuncLogicalContext *context) = 0;

    virtual antlrcpp::Any visitAtomExpr(CalcValueParser::AtomExprContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpr(CalcValueParser::AdditiveExprContext *context) = 0;

    virtual antlrcpp::Any visitColumnAtom(CalcValueParser::ColumnAtomContext *context) = 0;

    virtual antlrcpp::Any visitNumberAtom(CalcValueParser::NumberAtomContext *context) = 0;

    virtual antlrcpp::Any visitTextAtom(CalcValueParser::TextAtomContext *context) = 0;

    virtual antlrcpp::Any visitBooleanAtom(CalcValueParser::BooleanAtomContext *context) = 0;

    virtual antlrcpp::Any visitParExpr(CalcValueParser::ParExprContext *context) = 0;

    virtual antlrcpp::Any visitNoneExpr(CalcValueParser::NoneExprContext *context) = 0;
};

