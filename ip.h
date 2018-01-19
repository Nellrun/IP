#ifndef IP_H
#define IP_H

#include "predicate.h"
#include "lambda.h"
#include "variable.h"
#include "funcconstant.h"
#include "statement.h"
#include "divisor.h"
#include "step.h"
#include "wtype.h"
#include <typeinfo>

#define g 2

//struct W
//{
//    Statement* n;
//    Statement* d;
//    int q;
//};

struct N {
    std::vector<W*> w;
    int q;
};

//Функция унификации двух предикатов
Lambda* unification(Predicate* a, Predicate* b);

//Частичное деление дизъюнктов
WType* part_divide(Statement* b, Statement* d);

//Полное деление дизъюнктов
N* divide(std::vector<Statement*>* b, Statement* d);

//Базовая процедура вывода
void inference(std::vector<Statement*>* b, Statement* d);

//Процедура логического вывода, формирующая дерево шагов вывода
Step* conclusion(std::vector<StatementLambda*> D, Divisor* d, int depth, Step *parent = NULL,  int ind = 1);

Step* takeStep(std::vector<StatementLambda*> D, Divisor* d, Step* parent, int ind);

// Согласование
std::vector<Lambda*>* reconciliation(Step* root);

#endif // IP_H
