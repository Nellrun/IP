#ifndef DIVISOR_H
#define DIVISOR_H
#include "predicate.h"
#include "lambda.h"
#include "statement.h"
#include <vector>

struct d {
    Predicate* literal;
    Lambda* lambda;
};

class Divisor
{
public:
    Divisor();
    Divisor(Statement* s);

    std::vector<d*>* getLiterals() {
        return &literals;
    }

    void addLiteral(Predicate* p, Lambda* l);
    Divisor* copy();

    std::string toString(bool beauty = true);

    Divisor* replace(Lambda* l, int k);

    std::vector<d*> literals;
};

#endif // DIVISOR_H
