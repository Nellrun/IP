#ifndef STATEMENTLAMBDA_H
#define STATEMENTLAMBDA_H

#include "statement.h"
#include "lambda.h"
#include "divisor.h"

class StatementLambda
{
public:
    StatementLambda();
    StatementLambda(d* divisor);

    Statement* b;
    Lambda* l;
};
#endif // STATEMENTLAMBDA_H
