#ifndef STEP_H
#define STEP_H

#include "omega.h"
#include <vector>

/*!
    \class Step

    \brief Класс-структура, хранящий один шаг логического вывода
*/
class Step
{
public:
    Step();
    Step(Divisor* d, int depth);


    /*!
        \property Step::sons
        \brief Указатели на новые шаги логического вывода
        в дереве
     */
    std::vector<Step*> sons;

    /*!
        \property Step::q
        \brief Результата шага
     */
    int q;

    /*!
        \property Step::p
        \brief Признак продолжения вывода
     */
    int p;

    /*!
        \property Step::m
        \brief множество новых выводимых высказываний
     */
    std::vector<Divisor*> m;

    /*!
        \property Step::d
        \brief Выводимое высказывание на данном шаге
     */
    Divisor* d;


    /*!
        \property Step::с
        \brief выходное множество текущих остатков
     */
    std::vector<StatementLambda*> c;

    /*!
        \property Step::omegas
        \brief Структура содержащая все полные операций деления
        на заданном шаге
     */
    std::vector<Omega*> omegas;

    /*!
        \property Step::depth
        \brief Описывает глубину шага
     */
    int depth;
};

#endif // STEP_H
