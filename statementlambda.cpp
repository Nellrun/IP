#include "statementlambda.h"

StatementLambda::StatementLambda()
{
    b = new Statement();
    l = new Lambda();
}

StatementLambda::StatementLambda(d *divisor)
{
    b = new Statement();
    Predicate * newLiteral = divisor->literal->copy();
    newLiteral->setNegative(!newLiteral->isNegative());
    b->addLiteral(newLiteral);
    l = divisor->lambda->copy();
}
