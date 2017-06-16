#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "symbol.h"
#include "funcconstant.h"
#include "predicate.h"
#include "variable.h"
#include "constant.h"
#include <vector>

struct Statement
{
    std::vector<Predicate*>* predicates;
};


class Parser
{
public:
    Parser();
    Parser(std::string in);
    ~Parser();

    std::vector<Statement*>* parse();

private:
    Lexer* lexer;

    void error(std::string msg);
    Symbol* term();
    std::vector<Symbol*>* parenExpr();
    std::vector<Symbol*>* expr();
    Predicate* predicate();
    Statement* statement();

};

#endif // PARSER_H
