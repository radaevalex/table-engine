
// Generated from CalcValue.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CalcValueVisitor.h"


/**
 * This class provides an empty implementation of CalcValueVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalcValueBaseVisitor : public CalcValueVisitor {
public:

  virtual antlrcpp::Any visitParse(CalcValueParser::ParseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(CalcValueParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSumFunc(CalcValueParser::SumFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAverageFunc(CalcValueParser::AverageFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMedianFunc(CalcValueParser::MedianFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMinFunc(CalcValueParser::MinFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMaxFunc(CalcValueParser::MaxFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcatFunc(CalcValueParser::ConcatFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCountFunc(CalcValueParser::CountFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTextjoinFunc(CalcValueParser::TextjoinFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChooseFunc(CalcValueParser::ChooseFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfFunc(CalcValueParser::IfFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfsFunc(CalcValueParser::IfsFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchFunc(CalcValueParser::SwitchFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotFunc(CalcValueParser::NotFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndFunc(CalcValueParser::AndFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrFunc(CalcValueParser::OrFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDateFunc(CalcValueParser::DateFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeFunc(CalcValueParser::TimeFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYearFunc(CalcValueParser::YearFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMonthFunc(CalcValueParser::MonthFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDayFunc(CalcValueParser::DayFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHourFunc(CalcValueParser::HourFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMinuteFunc(CalcValueParser::MinuteFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSecondFunc(CalcValueParser::SecondFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNowFunc(CalcValueParser::NowFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTodayFunc(CalcValueParser::TodayFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWeekdayFunc(CalcValueParser::WeekdayFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWeekdayWithTypeFunc(CalcValueParser::WeekdayWithTypeFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprListFunc(CalcValueParser::ExprListFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamExprListFunc(CalcValueParser::ParamExprListFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncExpr(CalcValueParser::FuncExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDateTime(CalcValueParser::FuncDateTimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicationExpr(CalcValueParser::MultiplicationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionExpr(CalcValueParser::ConditionExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncLogical(CalcValueParser::FuncLogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomExpr(CalcValueParser::AtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpr(CalcValueParser::AdditiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnAtom(CalcValueParser::ColumnAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberAtom(CalcValueParser::NumberAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTextAtom(CalcValueParser::TextAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanAtom(CalcValueParser::BooleanAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParExpr(CalcValueParser::ParExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoneExpr(CalcValueParser::NoneExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

