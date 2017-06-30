#ifndef PREDICATE_H
#define PREDICATE_H

#include <iostream>
#include <string.h>
#include "funcconstant.h"
#include <vector>

class Predicate : public FuncConstant
{
public:
    Predicate();
    Predicate(std::string name, std::vector<Symbol> *symbols, bool negative);
    Predicate(std::string name, bool negative);

    Predicate* addSymbol(Symbol* s);
//    std::vector<Symbol>* getSymbols();

    bool isNegative();
//    std::string toString();
//    int getSize();
//    std::string getName();
    Predicate* copy();

    ~Predicate();



protected:
//    std::string name;
    bool negative;
//    std::vector<Symbol> symbols;
};

#endif // PREDICATE_H
