#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "Symbol.h"
#include "FuncConstant.h"
#include "Predicate.h"
#include "Variable.h"
#include "Constant.h"
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
