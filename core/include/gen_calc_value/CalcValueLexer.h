
// Generated from CalcValue.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CalcValueLexer : public antlr4::Lexer {
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

  CalcValueLexer(antlr4::CharStream *input);
  ~CalcValueLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

