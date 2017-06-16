#ifndef CONSTANT_H
#define CONSTANT_H

#include "symbol.h"

class Constant:Symbol
{
public:
    Constant(std::string name);
    Constant(std::string name, std::string value);

    std::string getValue();
    void setValue(std::string);
    Symbol* copy();

    ~Constant();

private:
    std::string value;
};

#endif // CONSTANT_H
