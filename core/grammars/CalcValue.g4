grammar CalcValue;

parse: '=' statement EOF;

statement: expr;

funcExprStatement
             : SUM '(' paramsExprList ')'                                           #sumFunc
             | AVERAGE '(' paramsExprList ')'                                       #averageFunc
             | MEDIAN '(' paramsExprList ')'                                        #medianFunc
             | MIN '(' paramsExprList ')'                                           #minFunc
             | MAX '(' paramsExprList ')'                                           #maxFunc
             | CONCAT '(' paramsExprList ')'                                        #concatFunc
             | COUNT '(' paramsExprList ')'                                         #countFunc
             | TEXTJOIN '(' expr ';' expr ';' paramsExprList ')'                    #textjoinFunc
             | CHOOSE '(' expr ';' paramsExprList ')'                               #chooseFunc

             ;

funcLogicalStatement
             : IF '(' expr ';' expr ';' expr ')'                                    #ifFunc
             | IFS '(' paramsExprList ')'                                           #ifsFunc
             | SWITCH '(' expr ';' paramsExprList ')'                               #switchFunc
             | NOT '(' expr ')'                                                     #notFunc
             | AND '(' paramsExprList ')'                                           #andFunc
             | OR '(' paramsExprList ')'                                            #orFunc
             ;

funcDateTimeStatement
             : DATE '(' expr ';' expr ';' expr ')'                                  #dateFunc
             | TIME '(' expr ';' expr ';' expr ')'                                  #timeFunc
             | YEAR '(' expr ')'                                                    #yearFunc
             | MONTH '(' expr ')'                                                   #monthFunc
             | DAY '(' expr ')'                                                     #dayFunc
             | HOUR '(' expr ')'                                                    #hourFunc
             | MINUTE '(' expr ')'                                                  #minuteFunc
             | SECOND '(' expr ')'                                                  #secondFunc
             | NOW '(' ')'                                                          #nowFunc
             | TODAY '(' ')'                                                        #todayFunc
             | WEEKDAY '(' expr ')'                                                 #weekdayFunc
             | WEEKDAY '(' expr ';'  expr ')'                                       #weekdayWithTypeFunc
             ;

paramsExprList
    : expr                                                                          #exprListFunc
    | paramsExprList ';' expr                                                       #paramExprListFunc
    ;

expr
    : expr op=(MULT | DIV | MOD) expr                                               #multiplicationExpr
    | expr op=(PLUS | MINUS) expr                                                   #additiveExpr
    | expr op=(EQUAL| NOTEQUAL| UNDER | OVER | UNDEREQUAL | OVEREQUAL) expr         #conditionExpr
    | funcExprStatement                                                             #funcExpr
    | funcLogicalStatement                                                          #funcLogical
    | funcDateTimeStatement                                                         #funcDateTime
    | atom                                                                          #atomExpr
    ;

atom
    : COLUMN                                                                        #columnAtom
    | (INT | FLOAT)                                                                 #numberAtom
    | STRING                                                                        #textAtom
    | (TRUE | FALSE)                                                                #booleanAtom
    | OPAR expr CPAR                                                                #parExpr
    |                                                                               #noneExpr
    ;

PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';
MOD : '%';
POW : '^';
EQUAL: '=';
NOTEQUAL: '<>';
UNDER: '<';
OVER: '>';
UNDEREQUAL: '<=';
OVEREQUAL: '>=';
AND: 'and';
OR: 'or';
NOT: 'not';
OPAR : '(';
CPAR : ')';

SUM: 'sum';
COUNT: 'count';
CONCAT: 'concat';
AVERAGE: 'average';
MEDIAN: 'median';
MIN: 'min';
MAX: 'max';
TEXTJOIN: 'textjoin';
TIME: 'time';
DATE: 'date';
YEAR: 'year';
MONTH: 'month';
DAY: 'day';
HOUR: 'hour';
MINUTE: 'minute';
SECOND: 'second';
NOW: 'now';
TODAY: 'today';
WEEKDAY: 'weekday';
IF: 'if';
IFS: 'ifs';
SWITCH: 'switch';
CHOOSE: 'choose';

TRUE : 'true';
FALSE : 'false';
COLUMN: [a-z] [a-z]*;
INT: [0-9]+;
FLOAT
    : [0-9] + '.' [0-9]*
    | '.' [0-9]+
    ;
STRING: '"' .*? '"' {setText(getText().substr(1, getText().size()-2));};

SPACE
    : [ \t\r\n] -> skip
    ;
