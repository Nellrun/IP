#include "parser.h"

Parser::Parser()
{
    lexer = new Lexer();
}

inline Parser::Parser(std::string in)
{
    lexer = new Lexer(in);
}

Parser::~Parser()
{
    delete lexer;
}

inline std::vector<Statement*>* Parser::parse()
{
    lexer->nextTok();
    std::vector<Statement*>* statements = new std::vector<Statement*>();
    Statement* s = statement();
    statements->push_back(s);

    for (auto &pred : (*s->predicates)) {
        std::cout << pred->getString() << " or ";
    }

    while (lexer->sym != Lexer_EOF) {
        statements->push_back(statement());
    }

    return statements;
}

inline void Parser::error(std::string msg)
{
    std::cout << "Parser error: " << msg << " at line " << lexer->line << " column " << lexer->column << std::endl;
    exit(1);
}

inline Symbol* Parser::term()
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
}

inline std::vector<Symbol*>* Parser::parenExpr()
{
    if (lexer->sym != Lexer_LPAR) {
        error("\"(\" expected");
    }
    lexer->nextTok();

    std::vector<Symbol*>* s = expr();

    if (lexer->sym != Lexer_RPAR) {
        error("\")\" expected");
    }
    lexer->nextTok();

    return s;
}

inline std::vector<Symbol*>* Parser::expr()
{
    std::vector<Symbol*>* v = new std::vector<Symbol*>;
    v->push_back(term());
    while (lexer->sym == Lexer_COMMA) {
        lexer->nextTok();
        v->push_back(term());
    }
    return v;
}

inline Predicate * Parser::predicate()
{
    if (lexer->sym == Lexer_ID) {
        std::string value = lexer->value;
        lexer->nextTok();
        return new Predicate(value, parenExpr());
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

inline Statement* Parser::statement()
{
    Statement* s = new Statement();
    s->predicates = new std::vector<Predicate*>;
    s->predicates->push_back(predicate());

    while (lexer->sym == Lexer_OR) {
        lexer->nextTok();
        s->predicates->push_back(predicate());
    }

    if (lexer->sym == Lexer_DOT) {
        lexer->nextTok();
        return s;
    }
    else {
        error("\".\" expected");
    }
}
