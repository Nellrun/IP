#ifndef OMEGA_H
#define OMEGA_H

#include "wtype.h"
#include "statement.h"
#include <vector>

//struct N
//{
//    Lambda* beta;
//    Statement* b;
//};

class Omega
{
public:
    Omega();

    /*!
        \property Omega::D
        \brief Высказывание, которое делится
     */
    StatementLambda D;

    /*!
        \property Omega::ws
        \brief Частичное деление дизъюнктов
     */
    std::vector<WType*> ws;

    /*!
        \property Omega::q
        \brief Результат полного деления
     */
    int q;

    /*!
        \property Omega::n
        \brief Остатки операции полного деления дизъюнктов
     */
//    std::vector<N*> n;

    /*!
        \property Omega::r
        \brief Подстановки
     */
    Lambda* r;
};

#endif // OMEGA_H
