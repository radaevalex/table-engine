
// Generated from CalcValue.g4 by ANTLR 4.8


#include "include/gen_calc_value/CalcValueVisitor.h"

#include "include/gen_calc_value/CalcValueParser.h"

using namespace antlrcpp;
using namespace antlr4;

CalcValueParser::CalcValueParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CalcValueParser::~CalcValueParser() {
  delete _interpreter;
}

std::string CalcValueParser::getGrammarFileName() const {
  return "CalcValue.g4";
}

const std::vector<std::string>& CalcValueParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CalcValueParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ParseContext ------------------------------------------------------------------

CalcValueParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcValueParser::ParseContext::EQUAL() {
  return getToken(CalcValueParser::EQUAL, 0);
}

CalcValueParser::StatementContext* CalcValueParser::ParseContext::statement() {
  return getRuleContext<CalcValueParser::StatementContext>(0);
}

tree::TerminalNode* CalcValueParser::ParseContext::EOF() {
  return getToken(CalcValueParser::EOF, 0);
}


size_t CalcValueParser::ParseContext::getRuleIndex() const {
  return CalcValueParser::RuleParse;
}


antlrcpp::Any CalcValueParser::ParseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitParse(this);
  else
    return visitor->visitChildren(this);
}

CalcValueParser::ParseContext* CalcValueParser::parse() {
  ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
  enterRule(_localctx, 0, CalcValueParser::RuleParse);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    match(CalcValueParser::EQUAL);
    setState(17);
    statement();
    setState(18);
    match(CalcValueParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CalcValueParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CalcValueParser::ExprContext* CalcValueParser::StatementContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}


size_t CalcValueParser::StatementContext::getRuleIndex() const {
  return CalcValueParser::RuleStatement;
}


antlrcpp::Any CalcValueParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CalcValueParser::StatementContext* CalcValueParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, CalcValueParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncExprStatementContext ------------------------------------------------------------------

CalcValueParser::FuncExprStatementContext::FuncExprStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcValueParser::FuncExprStatementContext::getRuleIndex() const {
  return CalcValueParser::RuleFuncExprStatement;
}

void CalcValueParser::FuncExprStatementContext::copyFrom(FuncExprStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MedianFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::MedianFuncContext::MEDIAN() {
  return getToken(CalcValueParser::MEDIAN, 0);
}

tree::TerminalNode* CalcValueParser::MedianFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::MedianFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::MedianFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::MedianFuncContext::MedianFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::MedianFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitMedianFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MaxFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::MaxFuncContext::MAX() {
  return getToken(CalcValueParser::MAX, 0);
}

tree::TerminalNode* CalcValueParser::MaxFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::MaxFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::MaxFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::MaxFuncContext::MaxFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::MaxFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitMaxFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ChooseFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::ChooseFuncContext::CHOOSE() {
  return getToken(CalcValueParser::CHOOSE, 0);
}

tree::TerminalNode* CalcValueParser::ChooseFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::ChooseFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::ChooseFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::ChooseFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::ChooseFuncContext::ChooseFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ChooseFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitChooseFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::MinFuncContext::MIN() {
  return getToken(CalcValueParser::MIN, 0);
}

tree::TerminalNode* CalcValueParser::MinFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::MinFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::MinFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::MinFuncContext::MinFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::MinFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitMinFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CountFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::CountFuncContext::COUNT() {
  return getToken(CalcValueParser::COUNT, 0);
}

tree::TerminalNode* CalcValueParser::CountFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::CountFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::CountFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::CountFuncContext::CountFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::CountFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitCountFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AverageFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::AverageFuncContext::AVERAGE() {
  return getToken(CalcValueParser::AVERAGE, 0);
}

tree::TerminalNode* CalcValueParser::AverageFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::AverageFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::AverageFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::AverageFuncContext::AverageFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::AverageFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitAverageFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SumFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::SumFuncContext::SUM() {
  return getToken(CalcValueParser::SUM, 0);
}

tree::TerminalNode* CalcValueParser::SumFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::SumFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::SumFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::SumFuncContext::SumFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::SumFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitSumFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TextjoinFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::TextjoinFuncContext::TEXTJOIN() {
  return getToken(CalcValueParser::TEXTJOIN, 0);
}

tree::TerminalNode* CalcValueParser::TextjoinFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

std::vector<CalcValueParser::ExprContext *> CalcValueParser::TextjoinFuncContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::TextjoinFuncContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::TextjoinFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::TextjoinFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::TextjoinFuncContext::TextjoinFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::TextjoinFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitTextjoinFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConcatFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::ConcatFuncContext::CONCAT() {
  return getToken(CalcValueParser::CONCAT, 0);
}

tree::TerminalNode* CalcValueParser::ConcatFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::ConcatFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::ConcatFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::ConcatFuncContext::ConcatFuncContext(FuncExprStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ConcatFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitConcatFunc(this);
  else
    return visitor->visitChildren(this);
}
CalcValueParser::FuncExprStatementContext* CalcValueParser::funcExprStatement() {
  FuncExprStatementContext *_localctx = _tracker.createInstance<FuncExprStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, CalcValueParser::RuleFuncExprStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcValueParser::SUM: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::SumFuncContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(22);
        match(CalcValueParser::SUM);
        setState(23);
        match(CalcValueParser::OPAR);
        setState(24);
        paramsExprList(0);
        setState(25);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::AVERAGE: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::AverageFuncContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(27);
        match(CalcValueParser::AVERAGE);
        setState(28);
        match(CalcValueParser::OPAR);
        setState(29);
        paramsExprList(0);
        setState(30);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::MEDIAN: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::MedianFuncContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(32);
        match(CalcValueParser::MEDIAN);
        setState(33);
        match(CalcValueParser::OPAR);
        setState(34);
        paramsExprList(0);
        setState(35);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::MIN: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::MinFuncContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(37);
        match(CalcValueParser::MIN);
        setState(38);
        match(CalcValueParser::OPAR);
        setState(39);
        paramsExprList(0);
        setState(40);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::MAX: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::MaxFuncContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(42);
        match(CalcValueParser::MAX);
        setState(43);
        match(CalcValueParser::OPAR);
        setState(44);
        paramsExprList(0);
        setState(45);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::CONCAT: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::ConcatFuncContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(47);
        match(CalcValueParser::CONCAT);
        setState(48);
        match(CalcValueParser::OPAR);
        setState(49);
        paramsExprList(0);
        setState(50);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::COUNT: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::CountFuncContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(52);
        match(CalcValueParser::COUNT);
        setState(53);
        match(CalcValueParser::OPAR);
        setState(54);
        paramsExprList(0);
        setState(55);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::TEXTJOIN: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::TextjoinFuncContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(57);
        match(CalcValueParser::TEXTJOIN);
        setState(58);
        match(CalcValueParser::OPAR);
        setState(59);
        expr(0);
        setState(60);
        match(CalcValueParser::T__0);
        setState(61);
        expr(0);
        setState(62);
        match(CalcValueParser::T__0);
        setState(63);
        paramsExprList(0);
        setState(64);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::CHOOSE: {
        _localctx = dynamic_cast<FuncExprStatementContext *>(_tracker.createInstance<CalcValueParser::ChooseFuncContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(66);
        match(CalcValueParser::CHOOSE);
        setState(67);
        match(CalcValueParser::OPAR);
        setState(68);
        expr(0);
        setState(69);
        match(CalcValueParser::T__0);
        setState(70);
        paramsExprList(0);
        setState(71);
        match(CalcValueParser::CPAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncLogicalStatementContext ------------------------------------------------------------------

CalcValueParser::FuncLogicalStatementContext::FuncLogicalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcValueParser::FuncLogicalStatementContext::getRuleIndex() const {
  return CalcValueParser::RuleFuncLogicalStatement;
}

void CalcValueParser::FuncLogicalStatementContext::copyFrom(FuncLogicalStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OrFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::OrFuncContext::OR() {
  return getToken(CalcValueParser::OR, 0);
}

tree::TerminalNode* CalcValueParser::OrFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::OrFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::OrFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::OrFuncContext::OrFuncContext(FuncLogicalStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::OrFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitOrFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfsFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::IfsFuncContext::IFS() {
  return getToken(CalcValueParser::IFS, 0);
}

tree::TerminalNode* CalcValueParser::IfsFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::IfsFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::IfsFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::IfsFuncContext::IfsFuncContext(FuncLogicalStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::IfsFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitIfsFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::IfFuncContext::IF() {
  return getToken(CalcValueParser::IF, 0);
}

tree::TerminalNode* CalcValueParser::IfFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

std::vector<CalcValueParser::ExprContext *> CalcValueParser::IfFuncContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::IfFuncContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::IfFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::IfFuncContext::IfFuncContext(FuncLogicalStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::IfFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitIfFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::NotFuncContext::NOT() {
  return getToken(CalcValueParser::NOT, 0);
}

tree::TerminalNode* CalcValueParser::NotFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::NotFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::NotFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::NotFuncContext::NotFuncContext(FuncLogicalStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::NotFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitNotFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SwitchFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::SwitchFuncContext::SWITCH() {
  return getToken(CalcValueParser::SWITCH, 0);
}

tree::TerminalNode* CalcValueParser::SwitchFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::SwitchFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::SwitchFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::SwitchFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::SwitchFuncContext::SwitchFuncContext(FuncLogicalStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::SwitchFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitSwitchFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::AndFuncContext::AND() {
  return getToken(CalcValueParser::AND, 0);
}

tree::TerminalNode* CalcValueParser::AndFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::AndFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

tree::TerminalNode* CalcValueParser::AndFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::AndFuncContext::AndFuncContext(FuncLogicalStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::AndFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitAndFunc(this);
  else
    return visitor->visitChildren(this);
}
CalcValueParser::FuncLogicalStatementContext* CalcValueParser::funcLogicalStatement() {
  FuncLogicalStatementContext *_localctx = _tracker.createInstance<FuncLogicalStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, CalcValueParser::RuleFuncLogicalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcValueParser::IF: {
        _localctx = dynamic_cast<FuncLogicalStatementContext *>(_tracker.createInstance<CalcValueParser::IfFuncContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(75);
        match(CalcValueParser::IF);
        setState(76);
        match(CalcValueParser::OPAR);
        setState(77);
        expr(0);
        setState(78);
        match(CalcValueParser::T__0);
        setState(79);
        expr(0);
        setState(80);
        match(CalcValueParser::T__0);
        setState(81);
        expr(0);
        setState(82);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::IFS: {
        _localctx = dynamic_cast<FuncLogicalStatementContext *>(_tracker.createInstance<CalcValueParser::IfsFuncContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(84);
        match(CalcValueParser::IFS);
        setState(85);
        match(CalcValueParser::OPAR);
        setState(86);
        paramsExprList(0);
        setState(87);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::SWITCH: {
        _localctx = dynamic_cast<FuncLogicalStatementContext *>(_tracker.createInstance<CalcValueParser::SwitchFuncContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(89);
        match(CalcValueParser::SWITCH);
        setState(90);
        match(CalcValueParser::OPAR);
        setState(91);
        expr(0);
        setState(92);
        match(CalcValueParser::T__0);
        setState(93);
        paramsExprList(0);
        setState(94);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::NOT: {
        _localctx = dynamic_cast<FuncLogicalStatementContext *>(_tracker.createInstance<CalcValueParser::NotFuncContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(96);
        match(CalcValueParser::NOT);
        setState(97);
        match(CalcValueParser::OPAR);
        setState(98);
        expr(0);
        setState(99);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::AND: {
        _localctx = dynamic_cast<FuncLogicalStatementContext *>(_tracker.createInstance<CalcValueParser::AndFuncContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(101);
        match(CalcValueParser::AND);
        setState(102);
        match(CalcValueParser::OPAR);
        setState(103);
        paramsExprList(0);
        setState(104);
        match(CalcValueParser::CPAR);
        break;
      }

      case CalcValueParser::OR: {
        _localctx = dynamic_cast<FuncLogicalStatementContext *>(_tracker.createInstance<CalcValueParser::OrFuncContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(106);
        match(CalcValueParser::OR);
        setState(107);
        match(CalcValueParser::OPAR);
        setState(108);
        paramsExprList(0);
        setState(109);
        match(CalcValueParser::CPAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDateTimeStatementContext ------------------------------------------------------------------

CalcValueParser::FuncDateTimeStatementContext::FuncDateTimeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcValueParser::FuncDateTimeStatementContext::getRuleIndex() const {
  return CalcValueParser::RuleFuncDateTimeStatement;
}

void CalcValueParser::FuncDateTimeStatementContext::copyFrom(FuncDateTimeStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- YearFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::YearFuncContext::YEAR() {
  return getToken(CalcValueParser::YEAR, 0);
}

tree::TerminalNode* CalcValueParser::YearFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::YearFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::YearFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::YearFuncContext::YearFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::YearFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitYearFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TodayFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::TodayFuncContext::TODAY() {
  return getToken(CalcValueParser::TODAY, 0);
}

tree::TerminalNode* CalcValueParser::TodayFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

tree::TerminalNode* CalcValueParser::TodayFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::TodayFuncContext::TodayFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::TodayFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitTodayFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MonthFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::MonthFuncContext::MONTH() {
  return getToken(CalcValueParser::MONTH, 0);
}

tree::TerminalNode* CalcValueParser::MonthFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::MonthFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::MonthFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::MonthFuncContext::MonthFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::MonthFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitMonthFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- HourFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::HourFuncContext::HOUR() {
  return getToken(CalcValueParser::HOUR, 0);
}

tree::TerminalNode* CalcValueParser::HourFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::HourFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::HourFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::HourFuncContext::HourFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::HourFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitHourFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SecondFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::SecondFuncContext::SECOND() {
  return getToken(CalcValueParser::SECOND, 0);
}

tree::TerminalNode* CalcValueParser::SecondFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::SecondFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::SecondFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::SecondFuncContext::SecondFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::SecondFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitSecondFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DateFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::DateFuncContext::DATE() {
  return getToken(CalcValueParser::DATE, 0);
}

tree::TerminalNode* CalcValueParser::DateFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

std::vector<CalcValueParser::ExprContext *> CalcValueParser::DateFuncContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::DateFuncContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::DateFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::DateFuncContext::DateFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::DateFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitDateFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TimeFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::TimeFuncContext::TIME() {
  return getToken(CalcValueParser::TIME, 0);
}

tree::TerminalNode* CalcValueParser::TimeFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

std::vector<CalcValueParser::ExprContext *> CalcValueParser::TimeFuncContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::TimeFuncContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::TimeFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::TimeFuncContext::TimeFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::TimeFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitTimeFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WeekdayFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::WeekdayFuncContext::WEEKDAY() {
  return getToken(CalcValueParser::WEEKDAY, 0);
}

tree::TerminalNode* CalcValueParser::WeekdayFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::WeekdayFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::WeekdayFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::WeekdayFuncContext::WeekdayFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::WeekdayFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitWeekdayFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinuteFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::MinuteFuncContext::MINUTE() {
  return getToken(CalcValueParser::MINUTE, 0);
}

tree::TerminalNode* CalcValueParser::MinuteFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::MinuteFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::MinuteFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::MinuteFuncContext::MinuteFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::MinuteFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitMinuteFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WeekdayWithTypeFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::WeekdayWithTypeFuncContext::WEEKDAY() {
  return getToken(CalcValueParser::WEEKDAY, 0);
}

tree::TerminalNode* CalcValueParser::WeekdayWithTypeFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

std::vector<CalcValueParser::ExprContext *> CalcValueParser::WeekdayWithTypeFuncContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::WeekdayWithTypeFuncContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::WeekdayWithTypeFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::WeekdayWithTypeFuncContext::WeekdayWithTypeFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::WeekdayWithTypeFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitWeekdayWithTypeFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DayFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::DayFuncContext::DAY() {
  return getToken(CalcValueParser::DAY, 0);
}

tree::TerminalNode* CalcValueParser::DayFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::DayFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::DayFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::DayFuncContext::DayFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::DayFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitDayFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NowFuncContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::NowFuncContext::NOW() {
  return getToken(CalcValueParser::NOW, 0);
}

tree::TerminalNode* CalcValueParser::NowFuncContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

tree::TerminalNode* CalcValueParser::NowFuncContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::NowFuncContext::NowFuncContext(FuncDateTimeStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::NowFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitNowFunc(this);
  else
    return visitor->visitChildren(this);
}
CalcValueParser::FuncDateTimeStatementContext* CalcValueParser::funcDateTimeStatement() {
  FuncDateTimeStatementContext *_localctx = _tracker.createInstance<FuncDateTimeStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, CalcValueParser::RuleFuncDateTimeStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::DateFuncContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(113);
      match(CalcValueParser::DATE);
      setState(114);
      match(CalcValueParser::OPAR);
      setState(115);
      expr(0);
      setState(116);
      match(CalcValueParser::T__0);
      setState(117);
      expr(0);
      setState(118);
      match(CalcValueParser::T__0);
      setState(119);
      expr(0);
      setState(120);
      match(CalcValueParser::CPAR);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::TimeFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(122);
      match(CalcValueParser::TIME);
      setState(123);
      match(CalcValueParser::OPAR);
      setState(124);
      expr(0);
      setState(125);
      match(CalcValueParser::T__0);
      setState(126);
      expr(0);
      setState(127);
      match(CalcValueParser::T__0);
      setState(128);
      expr(0);
      setState(129);
      match(CalcValueParser::CPAR);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::YearFuncContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(131);
      match(CalcValueParser::YEAR);
      setState(132);
      match(CalcValueParser::OPAR);
      setState(133);
      expr(0);
      setState(134);
      match(CalcValueParser::CPAR);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::MonthFuncContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(136);
      match(CalcValueParser::MONTH);
      setState(137);
      match(CalcValueParser::OPAR);
      setState(138);
      expr(0);
      setState(139);
      match(CalcValueParser::CPAR);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::DayFuncContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(141);
      match(CalcValueParser::DAY);
      setState(142);
      match(CalcValueParser::OPAR);
      setState(143);
      expr(0);
      setState(144);
      match(CalcValueParser::CPAR);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::HourFuncContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(146);
      match(CalcValueParser::HOUR);
      setState(147);
      match(CalcValueParser::OPAR);
      setState(148);
      expr(0);
      setState(149);
      match(CalcValueParser::CPAR);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::MinuteFuncContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(151);
      match(CalcValueParser::MINUTE);
      setState(152);
      match(CalcValueParser::OPAR);
      setState(153);
      expr(0);
      setState(154);
      match(CalcValueParser::CPAR);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::SecondFuncContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(156);
      match(CalcValueParser::SECOND);
      setState(157);
      match(CalcValueParser::OPAR);
      setState(158);
      expr(0);
      setState(159);
      match(CalcValueParser::CPAR);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::NowFuncContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(161);
      match(CalcValueParser::NOW);
      setState(162);
      match(CalcValueParser::OPAR);
      setState(163);
      match(CalcValueParser::CPAR);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::TodayFuncContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(164);
      match(CalcValueParser::TODAY);
      setState(165);
      match(CalcValueParser::OPAR);
      setState(166);
      match(CalcValueParser::CPAR);
      break;
    }

    case 11: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::WeekdayFuncContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(167);
      match(CalcValueParser::WEEKDAY);
      setState(168);
      match(CalcValueParser::OPAR);
      setState(169);
      expr(0);
      setState(170);
      match(CalcValueParser::CPAR);
      break;
    }

    case 12: {
      _localctx = dynamic_cast<FuncDateTimeStatementContext *>(_tracker.createInstance<CalcValueParser::WeekdayWithTypeFuncContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(172);
      match(CalcValueParser::WEEKDAY);
      setState(173);
      match(CalcValueParser::OPAR);
      setState(174);
      expr(0);
      setState(175);
      match(CalcValueParser::T__0);
      setState(176);
      expr(0);
      setState(177);
      match(CalcValueParser::CPAR);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsExprListContext ------------------------------------------------------------------

CalcValueParser::ParamsExprListContext::ParamsExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcValueParser::ParamsExprListContext::getRuleIndex() const {
  return CalcValueParser::RuleParamsExprList;
}

void CalcValueParser::ParamsExprListContext::copyFrom(ParamsExprListContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprListFuncContext ------------------------------------------------------------------

CalcValueParser::ExprContext* CalcValueParser::ExprListFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

CalcValueParser::ExprListFuncContext::ExprListFuncContext(ParamsExprListContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ExprListFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitExprListFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParamExprListFuncContext ------------------------------------------------------------------

CalcValueParser::ParamsExprListContext* CalcValueParser::ParamExprListFuncContext::paramsExprList() {
  return getRuleContext<CalcValueParser::ParamsExprListContext>(0);
}

CalcValueParser::ExprContext* CalcValueParser::ParamExprListFuncContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

CalcValueParser::ParamExprListFuncContext::ParamExprListFuncContext(ParamsExprListContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ParamExprListFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitParamExprListFunc(this);
  else
    return visitor->visitChildren(this);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::paramsExprList() {
   return paramsExprList(0);
}

CalcValueParser::ParamsExprListContext* CalcValueParser::paramsExprList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcValueParser::ParamsExprListContext *_localctx = _tracker.createInstance<ParamsExprListContext>(_ctx, parentState);
  CalcValueParser::ParamsExprListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CalcValueParser::RuleParamsExprList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ExprListFuncContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(182);
    expr(0);
    _ctx->stop = _input->LT(-1);
    setState(189);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ParamExprListFuncContext>(_tracker.createInstance<ParamsExprListContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleParamsExprList);
        setState(184);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(185);
        match(CalcValueParser::T__0);
        setState(186);
        expr(0); 
      }
      setState(191);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CalcValueParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcValueParser::ExprContext::getRuleIndex() const {
  return CalcValueParser::RuleExpr;
}

void CalcValueParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncExprContext ------------------------------------------------------------------

CalcValueParser::FuncExprStatementContext* CalcValueParser::FuncExprContext::funcExprStatement() {
  return getRuleContext<CalcValueParser::FuncExprStatementContext>(0);
}

CalcValueParser::FuncExprContext::FuncExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::FuncExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitFuncExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncDateTimeContext ------------------------------------------------------------------

CalcValueParser::FuncDateTimeStatementContext* CalcValueParser::FuncDateTimeContext::funcDateTimeStatement() {
  return getRuleContext<CalcValueParser::FuncDateTimeStatementContext>(0);
}

CalcValueParser::FuncDateTimeContext::FuncDateTimeContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::FuncDateTimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitFuncDateTime(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicationExprContext ------------------------------------------------------------------

std::vector<CalcValueParser::ExprContext *> CalcValueParser::MultiplicationExprContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::MultiplicationExprContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::MultiplicationExprContext::MULT() {
  return getToken(CalcValueParser::MULT, 0);
}

tree::TerminalNode* CalcValueParser::MultiplicationExprContext::DIV() {
  return getToken(CalcValueParser::DIV, 0);
}

tree::TerminalNode* CalcValueParser::MultiplicationExprContext::MOD() {
  return getToken(CalcValueParser::MOD, 0);
}

CalcValueParser::MultiplicationExprContext::MultiplicationExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::MultiplicationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitMultiplicationExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConditionExprContext ------------------------------------------------------------------

std::vector<CalcValueParser::ExprContext *> CalcValueParser::ConditionExprContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::ConditionExprContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::ConditionExprContext::EQUAL() {
  return getToken(CalcValueParser::EQUAL, 0);
}

tree::TerminalNode* CalcValueParser::ConditionExprContext::NOTEQUAL() {
  return getToken(CalcValueParser::NOTEQUAL, 0);
}

tree::TerminalNode* CalcValueParser::ConditionExprContext::UNDER() {
  return getToken(CalcValueParser::UNDER, 0);
}

tree::TerminalNode* CalcValueParser::ConditionExprContext::OVER() {
  return getToken(CalcValueParser::OVER, 0);
}

tree::TerminalNode* CalcValueParser::ConditionExprContext::UNDEREQUAL() {
  return getToken(CalcValueParser::UNDEREQUAL, 0);
}

tree::TerminalNode* CalcValueParser::ConditionExprContext::OVEREQUAL() {
  return getToken(CalcValueParser::OVEREQUAL, 0);
}

CalcValueParser::ConditionExprContext::ConditionExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ConditionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitConditionExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncLogicalContext ------------------------------------------------------------------

CalcValueParser::FuncLogicalStatementContext* CalcValueParser::FuncLogicalContext::funcLogicalStatement() {
  return getRuleContext<CalcValueParser::FuncLogicalStatementContext>(0);
}

CalcValueParser::FuncLogicalContext::FuncLogicalContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::FuncLogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitFuncLogical(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomExprContext ------------------------------------------------------------------

CalcValueParser::AtomContext* CalcValueParser::AtomExprContext::atom() {
  return getRuleContext<CalcValueParser::AtomContext>(0);
}

CalcValueParser::AtomExprContext::AtomExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExprContext ------------------------------------------------------------------

std::vector<CalcValueParser::ExprContext *> CalcValueParser::AdditiveExprContext::expr() {
  return getRuleContexts<CalcValueParser::ExprContext>();
}

CalcValueParser::ExprContext* CalcValueParser::AdditiveExprContext::expr(size_t i) {
  return getRuleContext<CalcValueParser::ExprContext>(i);
}

tree::TerminalNode* CalcValueParser::AdditiveExprContext::PLUS() {
  return getToken(CalcValueParser::PLUS, 0);
}

tree::TerminalNode* CalcValueParser::AdditiveExprContext::MINUS() {
  return getToken(CalcValueParser::MINUS, 0);
}

CalcValueParser::AdditiveExprContext::AdditiveExprContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::AdditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpr(this);
  else
    return visitor->visitChildren(this);
}

CalcValueParser::ExprContext* CalcValueParser::expr() {
   return expr(0);
}

CalcValueParser::ExprContext* CalcValueParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcValueParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalcValueParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, CalcValueParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FuncExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(193);
      funcExprStatement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FuncLogicalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(194);
      funcLogicalStatement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FuncDateTimeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(195);
      funcDateTimeStatement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(196);
      atom();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(208);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicationExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(199);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(200);
          dynamic_cast<MultiplicationExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CalcValueParser::MULT)
            | (1ULL << CalcValueParser::DIV)
            | (1ULL << CalcValueParser::MOD))) != 0))) {
            dynamic_cast<MultiplicationExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(201);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(203);
          dynamic_cast<AdditiveExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalcValueParser::PLUS

          || _la == CalcValueParser::MINUS)) {
            dynamic_cast<AdditiveExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(204);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ConditionExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(205);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(206);
          dynamic_cast<ConditionExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CalcValueParser::EQUAL)
            | (1ULL << CalcValueParser::NOTEQUAL)
            | (1ULL << CalcValueParser::UNDER)
            | (1ULL << CalcValueParser::OVER)
            | (1ULL << CalcValueParser::UNDEREQUAL)
            | (1ULL << CalcValueParser::OVEREQUAL))) != 0))) {
            dynamic_cast<ConditionExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(207);
          expr(6);
          break;
        }

        } 
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

CalcValueParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcValueParser::AtomContext::getRuleIndex() const {
  return CalcValueParser::RuleAtom;
}

void CalcValueParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleanAtomContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::BooleanAtomContext::TRUE() {
  return getToken(CalcValueParser::TRUE, 0);
}

tree::TerminalNode* CalcValueParser::BooleanAtomContext::FALSE() {
  return getToken(CalcValueParser::FALSE, 0);
}

CalcValueParser::BooleanAtomContext::BooleanAtomContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::BooleanAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitBooleanAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParExprContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::ParExprContext::OPAR() {
  return getToken(CalcValueParser::OPAR, 0);
}

CalcValueParser::ExprContext* CalcValueParser::ParExprContext::expr() {
  return getRuleContext<CalcValueParser::ExprContext>(0);
}

tree::TerminalNode* CalcValueParser::ParExprContext::CPAR() {
  return getToken(CalcValueParser::CPAR, 0);
}

CalcValueParser::ParExprContext::ParExprContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ParExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitParExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NoneExprContext ------------------------------------------------------------------

CalcValueParser::NoneExprContext::NoneExprContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::NoneExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitNoneExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TextAtomContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::TextAtomContext::STRING() {
  return getToken(CalcValueParser::STRING, 0);
}

CalcValueParser::TextAtomContext::TextAtomContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::TextAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitTextAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberAtomContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::NumberAtomContext::INT() {
  return getToken(CalcValueParser::INT, 0);
}

tree::TerminalNode* CalcValueParser::NumberAtomContext::FLOAT() {
  return getToken(CalcValueParser::FLOAT, 0);
}

CalcValueParser::NumberAtomContext::NumberAtomContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::NumberAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitNumberAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ColumnAtomContext ------------------------------------------------------------------

tree::TerminalNode* CalcValueParser::ColumnAtomContext::COLUMN() {
  return getToken(CalcValueParser::COLUMN, 0);
}

CalcValueParser::ColumnAtomContext::ColumnAtomContext(AtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CalcValueParser::ColumnAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcValueVisitor*>(visitor))
    return parserVisitor->visitColumnAtom(this);
  else
    return visitor->visitChildren(this);
}
CalcValueParser::AtomContext* CalcValueParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 14, CalcValueParser::RuleAtom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<CalcValueParser::ColumnAtomContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(213);
      match(CalcValueParser::COLUMN);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<CalcValueParser::NumberAtomContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(214);
      _la = _input->LA(1);
      if (!(_la == CalcValueParser::INT

      || _la == CalcValueParser::FLOAT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<CalcValueParser::TextAtomContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(215);
      match(CalcValueParser::STRING);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<CalcValueParser::BooleanAtomContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(216);
      _la = _input->LA(1);
      if (!(_la == CalcValueParser::TRUE

      || _la == CalcValueParser::FALSE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<CalcValueParser::ParExprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(217);
      match(CalcValueParser::OPAR);
      setState(218);
      expr(0);
      setState(219);
      match(CalcValueParser::CPAR);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<AtomContext *>(_tracker.createInstance<CalcValueParser::NoneExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CalcValueParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return paramsExprListSempred(dynamic_cast<ParamsExprListContext *>(context), predicateIndex);
    case 6: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalcValueParser::paramsExprListSempred(ParamsExprListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CalcValueParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CalcValueParser::_decisionToDFA;
atn::PredictionContextCache CalcValueParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CalcValueParser::_atn;
std::vector<uint16_t> CalcValueParser::_serializedATN;

std::vector<std::string> CalcValueParser::_ruleNames = {
  "parse", "statement", "funcExprStatement", "funcLogicalStatement", "funcDateTimeStatement", 
  "paramsExprList", "expr", "atom"
};

std::vector<std::string> CalcValueParser::_literalNames = {
  "", "';'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'='", "'<>'", "'<'", 
  "'>'", "'<='", "'>='", "'and'", "'or'", "'not'", "'('", "')'", "'sum'", 
  "'count'", "'concat'", "'average'", "'median'", "'min'", "'max'", "'textjoin'", 
  "'time'", "'date'", "'year'", "'month'", "'day'", "'hour'", "'minute'", 
  "'second'", "'now'", "'today'", "'weekday'", "'if'", "'ifs'", "'switch'", 
  "'choose'", "'true'", "'false'"
};

std::vector<std::string> CalcValueParser::_symbolicNames = {
  "", "", "PLUS", "MINUS", "MULT", "DIV", "MOD", "POW", "EQUAL", "NOTEQUAL", 
  "UNDER", "OVER", "UNDEREQUAL", "OVEREQUAL", "AND", "OR", "NOT", "OPAR", 
  "CPAR", "SUM", "COUNT", "CONCAT", "AVERAGE", "MEDIAN", "MIN", "MAX", "TEXTJOIN", 
  "TIME", "DATE", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "NOW", 
  "TODAY", "WEEKDAY", "IF", "IFS", "SWITCH", "CHOOSE", "TRUE", "FALSE", 
  "COLUMN", "INT", "FLOAT", "STRING", "SPACE"
};

dfa::Vocabulary CalcValueParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CalcValueParser::_tokenNames;

CalcValueParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x32, 0xe3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4c, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x72, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0xb6, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x7, 0x7, 0xbe, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xc1, 0xb, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xc8, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xd3, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
    0xd6, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xe1, 0xa, 0x9, 0x3, 0x9, 
    0x2, 0x4, 0xc, 0xe, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x2, 
    0x7, 0x3, 0x2, 0x6, 0x8, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0xa, 0xf, 0x3, 
    0x2, 0x2f, 0x30, 0x3, 0x2, 0x2c, 0x2d, 0x2, 0xfe, 0x2, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x71, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x13, 0x7, 0xa, 0x2, 0x2, 0x13, 0x14, 0x5, 0x4, 
    0x3, 0x2, 0x14, 0x15, 0x7, 0x2, 0x2, 0x3, 0x15, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x17, 0x5, 0xe, 0x8, 0x2, 0x17, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x19, 0x7, 0x15, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x13, 0x2, 0x2, 0x1a, 
    0x1b, 0x5, 0xc, 0x7, 0x2, 0x1b, 0x1c, 0x7, 0x14, 0x2, 0x2, 0x1c, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x18, 0x2, 0x2, 0x1e, 0x1f, 0x7, 
    0x13, 0x2, 0x2, 0x1f, 0x20, 0x5, 0xc, 0x7, 0x2, 0x20, 0x21, 0x7, 0x14, 
    0x2, 0x2, 0x21, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x19, 0x2, 
    0x2, 0x23, 0x24, 0x7, 0x13, 0x2, 0x2, 0x24, 0x25, 0x5, 0xc, 0x7, 0x2, 
    0x25, 0x26, 0x7, 0x14, 0x2, 0x2, 0x26, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x28, 0x7, 0x1a, 0x2, 0x2, 0x28, 0x29, 0x7, 0x13, 0x2, 0x2, 0x29, 0x2a, 
    0x5, 0xc, 0x7, 0x2, 0x2a, 0x2b, 0x7, 0x14, 0x2, 0x2, 0x2b, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x1b, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x13, 
    0x2, 0x2, 0x2e, 0x2f, 0x5, 0xc, 0x7, 0x2, 0x2f, 0x30, 0x7, 0x14, 0x2, 
    0x2, 0x30, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x17, 0x2, 0x2, 
    0x32, 0x33, 0x7, 0x13, 0x2, 0x2, 0x33, 0x34, 0x5, 0xc, 0x7, 0x2, 0x34, 
    0x35, 0x7, 0x14, 0x2, 0x2, 0x35, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0x7, 0x16, 0x2, 0x2, 0x37, 0x38, 0x7, 0x13, 0x2, 0x2, 0x38, 0x39, 0x5, 
    0xc, 0x7, 0x2, 0x39, 0x3a, 0x7, 0x14, 0x2, 0x2, 0x3a, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3c, 0x7, 0x1c, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x13, 0x2, 
    0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 0x2, 0x3e, 0x3f, 0x7, 0x3, 0x2, 0x2, 
    0x3f, 0x40, 0x5, 0xe, 0x8, 0x2, 0x40, 0x41, 0x7, 0x3, 0x2, 0x2, 0x41, 
    0x42, 0x5, 0xc, 0x7, 0x2, 0x42, 0x43, 0x7, 0x14, 0x2, 0x2, 0x43, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x2b, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x13, 0x2, 0x2, 0x46, 0x47, 0x5, 0xe, 0x8, 0x2, 0x47, 0x48, 0x7, 0x3, 
    0x2, 0x2, 0x48, 0x49, 0x5, 0xc, 0x7, 0x2, 0x49, 0x4a, 0x7, 0x14, 0x2, 
    0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x22, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x36, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x4e, 0x7, 0x28, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x13, 0x2, 
    0x2, 0x4f, 0x50, 0x5, 0xe, 0x8, 0x2, 0x50, 0x51, 0x7, 0x3, 0x2, 0x2, 
    0x51, 0x52, 0x5, 0xe, 0x8, 0x2, 0x52, 0x53, 0x7, 0x3, 0x2, 0x2, 0x53, 
    0x54, 0x5, 0xe, 0x8, 0x2, 0x54, 0x55, 0x7, 0x14, 0x2, 0x2, 0x55, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x29, 0x2, 0x2, 0x57, 0x58, 0x7, 
    0x13, 0x2, 0x2, 0x58, 0x59, 0x5, 0xc, 0x7, 0x2, 0x59, 0x5a, 0x7, 0x14, 
    0x2, 0x2, 0x5a, 0x72, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x2a, 0x2, 
    0x2, 0x5c, 0x5d, 0x7, 0x13, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0xe, 0x8, 0x2, 
    0x5e, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x5f, 0x60, 0x5, 0xc, 0x7, 0x2, 0x60, 
    0x61, 0x7, 0x14, 0x2, 0x2, 0x61, 0x72, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 
    0x7, 0x12, 0x2, 0x2, 0x63, 0x64, 0x7, 0x13, 0x2, 0x2, 0x64, 0x65, 0x5, 
    0xe, 0x8, 0x2, 0x65, 0x66, 0x7, 0x14, 0x2, 0x2, 0x66, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x68, 0x7, 0x10, 0x2, 0x2, 0x68, 0x69, 0x7, 0x13, 0x2, 
    0x2, 0x69, 0x6a, 0x5, 0xc, 0x7, 0x2, 0x6a, 0x6b, 0x7, 0x14, 0x2, 0x2, 
    0x6b, 0x72, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x11, 0x2, 0x2, 0x6d, 
    0x6e, 0x7, 0x13, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0xc, 0x7, 0x2, 0x6f, 0x70, 
    0x7, 0x14, 0x2, 0x2, 0x70, 0x72, 0x3, 0x2, 0x2, 0x2, 0x71, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x56, 0x3, 0x2, 0x2, 0x2, 0x71, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x62, 0x3, 0x2, 0x2, 0x2, 0x71, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x72, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x73, 0x74, 0x7, 0x1e, 0x2, 0x2, 0x74, 0x75, 0x7, 0x13, 0x2, 0x2, 0x75, 
    0x76, 0x5, 0xe, 0x8, 0x2, 0x76, 0x77, 0x7, 0x3, 0x2, 0x2, 0x77, 0x78, 
    0x5, 0xe, 0x8, 0x2, 0x78, 0x79, 0x7, 0x3, 0x2, 0x2, 0x79, 0x7a, 0x5, 
    0xe, 0x8, 0x2, 0x7a, 0x7b, 0x7, 0x14, 0x2, 0x2, 0x7b, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x7d, 0x7, 0x1d, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x13, 0x2, 
    0x2, 0x7e, 0x7f, 0x5, 0xe, 0x8, 0x2, 0x7f, 0x80, 0x7, 0x3, 0x2, 0x2, 
    0x80, 0x81, 0x5, 0xe, 0x8, 0x2, 0x81, 0x82, 0x7, 0x3, 0x2, 0x2, 0x82, 
    0x83, 0x5, 0xe, 0x8, 0x2, 0x83, 0x84, 0x7, 0x14, 0x2, 0x2, 0x84, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0x1f, 0x2, 0x2, 0x86, 0x87, 0x7, 
    0x13, 0x2, 0x2, 0x87, 0x88, 0x5, 0xe, 0x8, 0x2, 0x88, 0x89, 0x7, 0x14, 
    0x2, 0x2, 0x89, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x20, 0x2, 
    0x2, 0x8b, 0x8c, 0x7, 0x13, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0xe, 0x8, 0x2, 
    0x8d, 0x8e, 0x7, 0x14, 0x2, 0x2, 0x8e, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x90, 0x7, 0x21, 0x2, 0x2, 0x90, 0x91, 0x7, 0x13, 0x2, 0x2, 0x91, 0x92, 
    0x5, 0xe, 0x8, 0x2, 0x92, 0x93, 0x7, 0x14, 0x2, 0x2, 0x93, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x22, 0x2, 0x2, 0x95, 0x96, 0x7, 0x13, 
    0x2, 0x2, 0x96, 0x97, 0x5, 0xe, 0x8, 0x2, 0x97, 0x98, 0x7, 0x14, 0x2, 
    0x2, 0x98, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x23, 0x2, 0x2, 
    0x9a, 0x9b, 0x7, 0x13, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0xe, 0x8, 0x2, 0x9c, 
    0x9d, 0x7, 0x14, 0x2, 0x2, 0x9d, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 
    0x7, 0x24, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x13, 0x2, 0x2, 0xa0, 0xa1, 0x5, 
    0xe, 0x8, 0x2, 0xa1, 0xa2, 0x7, 0x14, 0x2, 0x2, 0xa2, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa4, 0x7, 0x25, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x13, 0x2, 
    0x2, 0xa5, 0xb6, 0x7, 0x14, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x26, 0x2, 0x2, 
    0xa7, 0xa8, 0x7, 0x13, 0x2, 0x2, 0xa8, 0xb6, 0x7, 0x14, 0x2, 0x2, 0xa9, 
    0xaa, 0x7, 0x27, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x13, 0x2, 0x2, 0xab, 0xac, 
    0x5, 0xe, 0x8, 0x2, 0xac, 0xad, 0x7, 0x14, 0x2, 0x2, 0xad, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x27, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x13, 
    0x2, 0x2, 0xb0, 0xb1, 0x5, 0xe, 0x8, 0x2, 0xb1, 0xb2, 0x7, 0x3, 0x2, 
    0x2, 0xb2, 0xb3, 0x5, 0xe, 0x8, 0x2, 0xb3, 0xb4, 0x7, 0x14, 0x2, 0x2, 
    0xb4, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x73, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x85, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0x99, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x9e, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x8, 0x7, 0x1, 0x2, 0xb8, 
    0xb9, 0x5, 0xe, 0x8, 0x2, 0xb9, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 
    0xc, 0x3, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x3, 0x2, 0x2, 0xbc, 0xbe, 0x5, 
    0xe, 0x8, 0x2, 0xbd, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc3, 0x8, 0x8, 0x1, 0x2, 0xc3, 0xc8, 0x5, 0x6, 0x4, 0x2, 0xc4, 
    0xc8, 0x5, 0x8, 0x5, 0x2, 0xc5, 0xc8, 0x5, 0xa, 0x6, 0x2, 0xc6, 0xc8, 
    0x5, 0x10, 0x9, 0x2, 0xc7, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0xc, 0x9, 0x2, 
    0x2, 0xca, 0xcb, 0x9, 0x2, 0x2, 0x2, 0xcb, 0xd3, 0x5, 0xe, 0x8, 0xa, 
    0xcc, 0xcd, 0xc, 0x8, 0x2, 0x2, 0xcd, 0xce, 0x9, 0x3, 0x2, 0x2, 0xce, 
    0xd3, 0x5, 0xe, 0x8, 0x9, 0xcf, 0xd0, 0xc, 0x7, 0x2, 0x2, 0xd0, 0xd1, 
    0x9, 0x4, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0xe, 0x8, 0x8, 0xd2, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xe1, 0x7, 0x2e, 0x2, 0x2, 0xd8, 
    0xe1, 0x9, 0x5, 0x2, 0x2, 0xd9, 0xe1, 0x7, 0x31, 0x2, 0x2, 0xda, 0xe1, 
    0x9, 0x6, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x13, 0x2, 0x2, 0xdc, 0xdd, 0x5, 
    0xe, 0x8, 0x2, 0xdd, 0xde, 0x7, 0x14, 0x2, 0x2, 0xde, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4b, 
    0x71, 0xb5, 0xbf, 0xc7, 0xd2, 0xd4, 0xe0, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CalcValueParser::Initializer CalcValueParser::_init;
