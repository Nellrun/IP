#ifndef PREDICATE_H
#define PREDICATE_H

#include <iostream>
#include <string.h>
#include "symbol.h"
#include <vector>

class Predicate
{
public:
    Predicate(std::string name, std::vector<Symbol*> *symbols, bool negative);
    Predicate(std::string name, bool negative);
    bool isNegative();
    std::string getString();
    std::vector<Symbol*>* getSymbols();
    int getSize();
    std::string getName();
    Predicate* copy();
    ~Predicate();



private:
    std::string name;
    bool negative;
    std::vector<Symbol*> *symbols;
};

#endif // PREDICATE_H
