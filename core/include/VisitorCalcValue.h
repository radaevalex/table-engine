#ifndef TABLE_ENGINE_VISITORCALCVALUE_H
#define TABLE_ENGINE_VISITORCALCVALUE_H

#include "engine.h"
#include "exception_collection.h"
#include "gen_calc_value/CalcValueVisitor.h"

/**
 * This class defines an visitor for a parse tree
 */
class VisitorCalcValue : public CalcValueVisitor {
   public:
    /**
     * @param nameColumns - map of matching id column with a letter to calculate a
     * formula
     * @param typeColumns - map of matching id column with type column
     * @param rowValues - row values
     * @param curDatetime - datetime to be used in calculations as the current
     * datetime
     */
    explicit VisitorCalcValue(
        const std::map<unsigned int, std::string> &nameColumns,
        const std::map<unsigned int, DvType> &typeColumns,
        std::map<unsigned int, DynamicValue> &rowValues,
        const time_t curDatetime = time(0));
    ~VisitorCalcValue() final{};

    /**
     * functions that make basic calculations
     */
    antlrcpp::Any visitParse(CalcValueParser::ParseContext *context) final;

    antlrcpp::Any visitStatement(
        CalcValueParser::StatementContext *context) final;

    antlrcpp::Any visitSumFunc(CalcValueParser::SumFuncContext *context) final;

    antlrcpp::Any visitAverageFunc(
        CalcValueParser::AverageFuncContext *context) final;

    antlrcpp::Any visitMedianFunc(
        CalcValueParser::MedianFuncContext *context) final;

    antlrcpp::Any visitMinFunc(CalcValueParser::MinFuncContext *context) final;

    antlrcpp::Any visitMaxFunc(CalcValueParser::MaxFuncContext *context) final;

    antlrcpp::Any visitCountFunc(
        CalcValueParser::CountFuncContext *context) final;

    antlrcpp::Any visitDateFunc(
        CalcValueParser::DateFuncContext *context) final;

    antlrcpp::Any visitTimeFunc(
        CalcValueParser::TimeFuncContext *context) final;

    antlrcpp::Any visitYearFunc(
        CalcValueParser::YearFuncContext *context) final;

    antlrcpp::Any visitMonthFunc(
        CalcValueParser::MonthFuncContext *context) final;

    antlrcpp::Any visitDayFunc(CalcValueParser::DayFuncContext *context) final;

    antlrcpp::Any visitHourFunc(
        CalcValueParser::HourFuncContext *context) final;

    antlrcpp::Any visitMinuteFunc(
        CalcValueParser::MinuteFuncContext *context) final;

    antlrcpp::Any visitSecondFunc(
        CalcValueParser::SecondFuncContext *context) final;

    antlrcpp::Any visitNowFunc(CalcValueParser::NowFuncContext *context) final;

    antlrcpp::Any visitTodayFunc(
        CalcValueParser::TodayFuncContext *context) final;

    antlrcpp::Any visitWeekdayFunc(
        CalcValueParser::WeekdayFuncContext *context) final;

    antlrcpp::Any visitNotFunc(CalcValueParser::NotFuncContext *context) final;

    antlrcpp::Any visitAndFunc(CalcValueParser::AndFuncContext *context) final;

    antlrcpp::Any visitOrFunc(CalcValueParser::OrFuncContext *context) final;

    antlrcpp::Any visitWeekdayWithTypeFunc(
        CalcValueParser::WeekdayWithTypeFuncContext *context) final;

    antlrcpp::Any visitConcatFunc(
        CalcValueParser::ConcatFuncContext *context) final;

    antlrcpp::Any visitTextjoinFunc(
        CalcValueParser::TextjoinFuncContext *context) final;

    antlrcpp::Any visitIfFunc(CalcValueParser::IfFuncContext *context) final;

    antlrcpp::Any visitIfsFunc(CalcValueParser::IfsFuncContext *context) final;

    antlrcpp::Any visitChooseFunc(
        CalcValueParser::ChooseFuncContext *context) final;

    antlrcpp::Any visitSwitchFunc(
        CalcValueParser::SwitchFuncContext *context) final;

    antlrcpp::Any visitExprListFunc(
        CalcValueParser::ExprListFuncContext *context) final;

    antlrcpp::Any visitParamExprListFunc(
        CalcValueParser::ParamExprListFuncContext *context) final;

    antlrcpp::Any visitFuncExpr(
        CalcValueParser::FuncExprContext *context) final;

    antlrcpp::Any visitFuncDateTime(
        CalcValueParser::FuncDateTimeContext *context) final;

    antlrcpp::Any visitMultiplicationExpr(
        CalcValueParser::MultiplicationExprContext *context) final;

    antlrcpp::Any visitConditionExpr(
        CalcValueParser::ConditionExprContext *context) final;

    antlrcpp::Any visitFuncLogical(
        CalcValueParser::FuncLogicalContext *context) final;

    antlrcpp::Any visitAtomExpr(
        CalcValueParser::AtomExprContext *context) final;

    antlrcpp::Any visitAdditiveExpr(
        CalcValueParser::AdditiveExprContext *context) final;

    antlrcpp::Any visitTextAtom(
        CalcValueParser::TextAtomContext *context) final;

    antlrcpp::Any visitColumnAtom(
        CalcValueParser::ColumnAtomContext *context) final;

    antlrcpp::Any visitNumberAtom(
        CalcValueParser::NumberAtomContext *context) final;

    antlrcpp::Any visitParExpr(CalcValueParser::ParExprContext *context) final;

    antlrcpp::Any visitBooleanAtom(
        CalcValueParser::BooleanAtomContext *context) final;

    antlrcpp::Any visitNoneExpr(
        CalcValueParser::NoneExprContext *context) final;

   private:
    const std::map<unsigned int, DynamicValue> &_rowValues;
    std::map<std::string, unsigned int> _columnsByName;
    std::map<std::string, DvType> _typeColumnsByName;
    const time_t _curDatetime;
    std::tm _tmInitTime = {0, 0, 0, 1, 0, 70};
    const time_t _initTime = timelocal(&_tmInitTime);

    /**
     * throws error
     * @param expression - message error
     */
    void _throw_type_error(const std::string &expression);
};

#endif  // TABLE_ENGINE_VISITORCALCVALUE_H
