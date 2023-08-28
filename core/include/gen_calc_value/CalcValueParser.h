
// Generated from CalcValue.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CalcValueParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, PLUS = 2, MINUS = 3, MULT = 4, DIV = 5, MOD = 6, POW = 7, 
    EQUAL = 8, NOTEQUAL = 9, UNDER = 10, OVER = 11, UNDEREQUAL = 12, OVEREQUAL = 13, 
    AND = 14, OR = 15, NOT = 16, OPAR = 17, CPAR = 18, SUM = 19, COUNT = 20, 
    CONCAT = 21, AVERAGE = 22, MEDIAN = 23, MIN = 24, MAX = 25, TEXTJOIN = 26, 
    TIME = 27, DATE = 28, YEAR = 29, MONTH = 30, DAY = 31, HOUR = 32, MINUTE = 33, 
    SECOND = 34, NOW = 35, TODAY = 36, WEEKDAY = 37, IF = 38, IFS = 39, 
    SWITCH = 40, CHOOSE = 41, TRUE = 42, FALSE = 43, COLUMN = 44, INT = 45, 
    FLOAT = 46, STRING = 47, SPACE = 48
  };

  enum {
    RuleParse = 0, RuleStatement = 1, RuleFuncExprStatement = 2, RuleFuncLogicalStatement = 3, 
    RuleFuncDateTimeStatement = 4, RuleParamsExprList = 5, RuleExpr = 6, 
    RuleAtom = 7
  };

  CalcValueParser(antlr4::TokenStream *input);
  ~CalcValueParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ParseContext;
  class StatementContext;
  class FuncExprStatementContext;
  class FuncLogicalStatementContext;
  class FuncDateTimeStatementContext;
  class ParamsExprListContext;
  class ExprContext;
  class AtomContext; 

  class  ParseContext : public antlr4::ParserRuleContext {
  public:
    ParseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    StatementContext *statement();
    antlr4::tree::TerminalNode *EOF();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParseContext* parse();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  FuncExprStatementContext : public antlr4::ParserRuleContext {
  public:
    FuncExprStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FuncExprStatementContext() = default;
    void copyFrom(FuncExprStatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MedianFuncContext : public FuncExprStatementContext {
  public:
    MedianFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *MEDIAN();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MaxFuncContext : public FuncExprStatementContext {
  public:
    MaxFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *MAX();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ChooseFuncContext : public FuncExprStatementContext {
  public:
    ChooseFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *CHOOSE();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MinFuncContext : public FuncExprStatementContext {
  public:
    MinFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *MIN();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CountFuncContext : public FuncExprStatementContext {
  public:
    CountFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *COUNT();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AverageFuncContext : public FuncExprStatementContext {
  public:
    AverageFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *AVERAGE();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SumFuncContext : public FuncExprStatementContext {
  public:
    SumFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *SUM();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TextjoinFuncContext : public FuncExprStatementContext {
  public:
    TextjoinFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *TEXTJOIN();
    antlr4::tree::TerminalNode *OPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConcatFuncContext : public FuncExprStatementContext {
  public:
    ConcatFuncContext(FuncExprStatementContext *ctx);

    antlr4::tree::TerminalNode *CONCAT();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncExprStatementContext* funcExprStatement();

  class  FuncLogicalStatementContext : public antlr4::ParserRuleContext {
  public:
    FuncLogicalStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FuncLogicalStatementContext() = default;
    void copyFrom(FuncLogicalStatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OrFuncContext : public FuncLogicalStatementContext {
  public:
    OrFuncContext(FuncLogicalStatementContext *ctx);

    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfsFuncContext : public FuncLogicalStatementContext {
  public:
    IfsFuncContext(FuncLogicalStatementContext *ctx);

    antlr4::tree::TerminalNode *IFS();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfFuncContext : public FuncLogicalStatementContext {
  public:
    IfFuncContext(FuncLogicalStatementContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *OPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotFuncContext : public FuncLogicalStatementContext {
  public:
    NotFuncContext(FuncLogicalStatementContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SwitchFuncContext : public FuncLogicalStatementContext {
  public:
    SwitchFuncContext(FuncLogicalStatementContext *ctx);

    antlr4::tree::TerminalNode *SWITCH();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndFuncContext : public FuncLogicalStatementContext {
  public:
    AndFuncContext(FuncLogicalStatementContext *ctx);

    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OPAR();
    ParamsExprListContext *paramsExprList();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncLogicalStatementContext* funcLogicalStatement();

  class  FuncDateTimeStatementContext : public antlr4::ParserRuleContext {
  public:
    FuncDateTimeStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FuncDateTimeStatementContext() = default;
    void copyFrom(FuncDateTimeStatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  YearFuncContext : public FuncDateTimeStatementContext {
  public:
    YearFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *YEAR();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TodayFuncContext : public FuncDateTimeStatementContext {
  public:
    TodayFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *TODAY();
    antlr4::tree::TerminalNode *OPAR();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MonthFuncContext : public FuncDateTimeStatementContext {
  public:
    MonthFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *MONTH();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  HourFuncContext : public FuncDateTimeStatementContext {
  public:
    HourFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *HOUR();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SecondFuncContext : public FuncDateTimeStatementContext {
  public:
    SecondFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *SECOND();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DateFuncContext : public FuncDateTimeStatementContext {
  public:
    DateFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *OPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TimeFuncContext : public FuncDateTimeStatementContext {
  public:
    TimeFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *OPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WeekdayFuncContext : public FuncDateTimeStatementContext {
  public:
    WeekdayFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *WEEKDAY();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MinuteFuncContext : public FuncDateTimeStatementContext {
  public:
    MinuteFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *MINUTE();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WeekdayWithTypeFuncContext : public FuncDateTimeStatementContext {
  public:
    WeekdayWithTypeFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *WEEKDAY();
    antlr4::tree::TerminalNode *OPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DayFuncContext : public FuncDateTimeStatementContext {
  public:
    DayFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *DAY();
    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NowFuncContext : public FuncDateTimeStatementContext {
  public:
    NowFuncContext(FuncDateTimeStatementContext *ctx);

    antlr4::tree::TerminalNode *NOW();
    antlr4::tree::TerminalNode *OPAR();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncDateTimeStatementContext* funcDateTimeStatement();

  class  ParamsExprListContext : public antlr4::ParserRuleContext {
  public:
    ParamsExprListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ParamsExprListContext() = default;
    void copyFrom(ParamsExprListContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprListFuncContext : public ParamsExprListContext {
  public:
    ExprListFuncContext(ParamsExprListContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParamExprListFuncContext : public ParamsExprListContext {
  public:
    ParamExprListFuncContext(ParamsExprListContext *ctx);

    ParamsExprListContext *paramsExprList();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ParamsExprListContext* paramsExprList();
  ParamsExprListContext* paramsExprList(int precedence);
  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FuncExprContext : public ExprContext {
  public:
    FuncExprContext(ExprContext *ctx);

    FuncExprStatementContext *funcExprStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncDateTimeContext : public ExprContext {
  public:
    FuncDateTimeContext(ExprContext *ctx);

    FuncDateTimeStatementContext *funcDateTimeStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplicationExprContext : public ExprContext {
  public:
    MultiplicationExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConditionExprContext : public ExprContext {
  public:
    ConditionExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NOTEQUAL();
    antlr4::tree::TerminalNode *UNDER();
    antlr4::tree::TerminalNode *OVER();
    antlr4::tree::TerminalNode *UNDEREQUAL();
    antlr4::tree::TerminalNode *OVEREQUAL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncLogicalContext : public ExprContext {
  public:
    FuncLogicalContext(ExprContext *ctx);

    FuncLogicalStatementContext *funcLogicalStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomExprContext : public ExprContext {
  public:
    AtomExprContext(ExprContext *ctx);

    AtomContext *atom();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AdditiveExprContext : public ExprContext {
  public:
    AdditiveExprContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BooleanAtomContext : public AtomContext {
  public:
    BooleanAtomContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParExprContext : public AtomContext {
  public:
    ParExprContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *OPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NoneExprContext : public AtomContext {
  public:
    NoneExprContext(AtomContext *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TextAtomContext : public AtomContext {
  public:
    TextAtomContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberAtomContext : public AtomContext {
  public:
    NumberAtomContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ColumnAtomContext : public AtomContext {
  public:
    ColumnAtomContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *COLUMN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AtomContext* atom();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool paramsExprListSempred(ParamsExprListContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

