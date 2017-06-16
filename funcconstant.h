#ifndef FUNCCONSTANT_H
#define FUNCCONSTANT_H

#include <string>
#include <vector>
#include "symbol.h"

class FuncConstant:Symbol
{
public:
    FuncConstant(std::string name, std::vector<Symbol*> *symbols);
    FuncConstant(std::string name);
    std::string getString();
    std::vector<Symbol*>* getSymbols();
    void setSymbols(std::vector<Symbol*>* s);
    void replace(Symbol* from, Symbol* to);
    bool contain(Symbol* s);
    Symbol* copy();
    ~FuncConstant();

private:
    std::vector<Symbol*>* symbols;
    bool negative;
};

#endif // FUNCCONSTANT_H
