#ifndef IP_H
#define IP_H

#include "predicate.h"
#include "lambda.h"
#include "variable.h"
#include "funcconstant.h"
#include <typeinfo>

#define g 2

struct W
{
    Predicate** b;
    int sizeB;
    Predicate** d;
    int sizeD;
    Lambda* l;
    int q;
};

//Функция унификации двух предикатов
Lambda* unification(Predicate* a, Predicate* b);

std::list<W> w_operation(Predicate** D, int sizeD, Predicate** d, int sized);

#endif // IP_H
