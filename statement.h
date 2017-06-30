#ifndef STATEMENT_H
#define STATEMENT_H

#include "predicate.h"

class Statement
{
public:
    Statement();

    std::vector<Predicate>* getPredicates();
    Statement* addPredicate(Predicate*);
    std::string toString();

private:
    std::vector<Predicate> predicates;
};

#endif // STATEMENT_H
