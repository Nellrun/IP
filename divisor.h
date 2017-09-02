#ifndef DIVISOR_H
#define DIVISOR_H
#include "predicate.h"
#include "lambda.h"
#include <vector>

struct d {
    Preducate literal;
    Lambda lambda;
};

class Divisor
{
public:
    Divisor();

    std::vector<d> literals;
};

#endif // DIVISOR_H
