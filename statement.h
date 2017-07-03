#ifndef STATEMENT_H
#define STATEMENT_H

#include "predicate.h"
#include "lambda.h"

class Statement
{
public:
    Statement();

    std::vector<Predicate*>* getPredicates();
    void addPredicate(Predicate*);
    std::string toString(bool beauty = true);

    int getSize();

    Statement* replace(Lambda* l, int id);
    Statement* copy(bool inverse = false);

private:
    std::vector<Predicate*> predicates;
};

#endif // STATEMENT_H
