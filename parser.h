#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "symbol.h"
#include "funcconstant.h"
#include "predicate.h"
#include "variable.h"
#include "constant.h"
#include <vector>
#include "statement.h"
#include "wtype.h"


class ParserAnalysisException {};

class Parser
{
public:
    Parser();
    Parser(std::string in);
    ~Parser();

    std::vector<StatementLambda*>* parse();

    std::string errorMsg;

    bool getErrorState();

private:
    Lexer* lexer;

    void error(std::string msg);
    Symbol* term();
    std::vector<Symbol*>* parenExpr();
    std::vector<Symbol*>* expr();
    Predicate* predicate();
    StatementLambda* statement();

    bool errorStatus;
};

#endif // PARSER_H
