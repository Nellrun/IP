#include "parser.h"

Parser::Parser()
{
    lexer = new Lexer();
}

Parser::Parser(std::string in)
{
    lexer = new Lexer(in);
}

Parser::~Parser()
{
    delete lexer;
}

std::vector<Statement*>* Parser::parse()
{
    lexer->nextTok();
    std::vector<Statement*>* statements = new std::vector<Statement*>();
    Statement* s = statement();
    statements->push_back(s);

    while (lexer->sym != Lexer_EOF) {
        statements->push_back(statement());
    }

    return statements;
}

void Parser::error(std::string msg)
{
    errorMsg = "Parser error: " + msg + " at line " + std::to_string(lexer->line)
            + " column " + std::to_string(lexer->column);
    std::cout << errorMsg << std::endl;
//    exit(1);
}

Symbol* Parser::term()
{
    if (lexer->sym == Lexer_ID) {
        std::string value = lexer->value;
        lexer->nextTok();

        if (lexer->sym == Lexer_LPAR) {
            return (Symbol*) new FuncConstant(value, parenExpr());
        }
        else {
            if (isupper(value[0])) {
                return (Symbol*) new Constant(value);
            }
            else {
                return (Symbol*) new Variable(value);
            }
        }
    }
    else {

    }
    return NULL;
}

std::vector<Symbol>* Parser::parenExpr()
{
    if (lexer->sym != Lexer_LPAR) {
        error("\"(\" expected");
    }
    lexer->nextTok();

    std::vector<Symbol>* s = expr();

    if (lexer->sym != Lexer_RPAR) {
        error("\")\" expected");
    }
    lexer->nextTok();

    return s;
}

std::vector<Symbol>* Parser::expr()
{
    std::vector<Symbol>* v = new std::vector<Symbol>;
    v->push_back(*term());
    while (lexer->sym == Lexer_COMMA) {
        lexer->nextTok();
        v->push_back(*term());
    }
    return v;
}

Predicate * Parser::predicate()
{
    if (lexer->sym == Lexer_ID) {
        std::string value = lexer->value;
        lexer->nextTok();
        return new Predicate(value, parenExpr(), false);
    }
    else if (lexer->sym == Lexer_NOT) {
        lexer->nextTok();
        if (lexer->sym == Lexer_ID) {
            std::string value = lexer->value;
            lexer->nextTok();
            return new Predicate(value, parenExpr(), true);
        }
        else {
            error("predicat expected");
        }
    }
    else {
        error("predicat expected");
    }
}

Statement* Parser::statement()
{
    Statement* s = new Statement();
    s->addPredicate(predicate());

    while (lexer->sym == Lexer_OR) {
        lexer->nextTok();
        s->addPredicate(predicate());
    }

    if (lexer->sym == Lexer_DOT) {
        lexer->nextTok();
        return s;
    }
    else {
        error("\".\" expected");
    }
}
