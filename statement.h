#ifndef STATEMENT_H
#define STATEMENT_H

#include "predicate.h"
#include "lambda.h"

class Statement
{
public:
    Statement();

    std::vector<Predicate*>* getPredicates();
    Statement* addPredicate(Predicate*);
    std::string toString();

    Statement* replace(Lambda* l, int id);

private:
    std::vector<Predicate*> predicates;
};

#endif // STATEMENT_H
