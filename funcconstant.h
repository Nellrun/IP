#ifndef FUNCCONSTANT_H
#define FUNCCONSTANT_H

#include <string>
#include <vector>
#include "symbol.h"
#include "variable.h"

class FuncConstant: public Symbol
{
public:

    FuncConstant();
    FuncConstant(std::string name, std::vector<Symbol*> *symbols);
    FuncConstant(std::string name);
    std::string toString();

    std::vector<Symbol*>* getSymbols();
    void setSymbols(std::vector<Symbol*>* s);
    FuncConstant* addSymbol(Symbol* s);
    void setLevel(int lvl);

    int getSize();

    void replace(Symbol* from, Symbol* to);
    bool contain(Symbol* s);
    Symbol* copy();
    ~FuncConstant();

protected:
    std::vector<Symbol*> symbols;
//    bool negative;
};

#endif // FUNCCONSTANT_H
