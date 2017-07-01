#ifndef IP_H
#define IP_H

#include "predicate.h"
#include "lambda.h"
#include "variable.h"
#include "funcconstant.h"
#include "statement.h"
#include <typeinfo>

#define g 2

struct W
{
    Statement* n;
    Statement* d;
    int q;
};

struct N {
    std::vector<W*> w;
    int q;
};

//Функция унификации двух предикатов
Lambda* unification(Predicate* a, Predicate* b);

//Частичное деление дизъюнктов
std::vector<W*>* part_divide(Statement* b, Statement* d);

//Полное деление дизъюнктов
N* divide(std::vector<Statement*>* b, Statement* d);

#endif // IP_H
