#ifndef STATEMENT_H
#define STATEMENT_H

#include "predicate.h"
#include "lambda.h"

class Statement
{
public:
    Statement();

    std::vector<Predicate*>* getLiterals();
    void addLiteral(Predicate*);
    std::string toString(bool beauty = true);

    int getSize();

    bool isEqual(Statement* b);
    Statement* replace(Lambda* l, int id);
    Statement* copy(bool inverse = false);
    void setLevel(int lvl, int ind);

private:
    std::vector<Predicate*> literals;
};

#endif // STATEMENT_H
