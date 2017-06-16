#ifndef VARIABLE_H
#define VARIABLE_H


#include <string>
#include "Symbol.h"


class Variable:Symbol
{
public:
    Variable(std::string name);
    Symbol* copy();
    ~Variable();

private:
};

#endif // VARIABLE_H
