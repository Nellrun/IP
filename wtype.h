#ifndef WTYPE_H
#define WTYPE_H

#include "lambda.h"
#include "statement.h"
#include "divisor.h"
#include "statementlambda.h"

struct W
{
    StatementLambda* n;
    Divisor* d;
};

class WType
{
public:
    WType();

    /*!
        \property WType::q
        \brief Результат частичного деления дизъюнктов
     */
    int q;


    /*!
        \property WType::b
        \brief Исходный остаток
     */
    StatementLambda b;

    /*!
        \property WType::n
        \brief Новые остатки-делимые и остатки делители
     */
    std::vector<W*> n;

    /*!
        \property WType::d
        \brief Делитель
     */
    Divisor d;

    /*!
        \property WType::r
        \brief Множество решений-подстановок полученных в результате деления
     */
    std::vector<Lambda*> r;
};

#endif // WTYPE_H
