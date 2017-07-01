#include "funcconstant.h"

#include <typeinfo>

FuncConstant::FuncConstant() {

}

FuncConstant::FuncConstant(std::string name) {
   id = SymbolTable::getInstance()->addSymbol(name);
}

FuncConstant::FuncConstant(std::string name, std::vector<Symbol*> *symbols) {
    id = SymbolTable::getInstance()->addSymbol(name);
    this->symbols = *symbols;
}

std::string FuncConstant::toString() {
    std::string out = SymbolTable::getInstance()->getSymbol(id) + "(";
    for (unsigned i = 0; i < (symbols.size() - 1); i++) {
        out += symbols[i]->toString() + ", ";
    }

    out += symbols[symbols.size() - 1]->toString() + ")";

    return out;
}

FuncConstant* FuncConstant::addSymbol(Symbol* s) {
    symbols.push_back(s);
    return this;
}

std::vector<Symbol*>* FuncConstant::getSymbols()
{
    return &symbols;
}

void FuncConstant::setSymbols(std::vector<Symbol*>* s)
{
//    symbols = *s;
}

int FuncConstant::getSize() {
    return symbols.size();
}

void FuncConstant::replace(Symbol* from, Symbol* to)
{
    for (unsigned i = 0; i < symbols.size(); i++) {
        if (symbols[i]->cmp(*from)) {
            symbols[i] = to;
        }
//        if (symbols[i]->getID() == from) {
//            symbols[i]->setID(to);
//        }
        if (typeid(symbols[i]) == typeid(FuncConstant)) {
            ((FuncConstant*) &symbols[i])->replace(from, to);
//            ((FuncConstant)symbols[i]).replace(from, to);
        }
    }
}

bool FuncConstant::contain(Symbol * s)
{
    for (unsigned i = 0; i < symbols.size(); i++) {
        if (symbols[i]->cmp(*s)) return true;
        if ((typeid(symbols[i]) == typeid(FuncConstant)) && (((FuncConstant*)&symbols[i])->contain(s))) return true;
    }
    return false;
}

Symbol * FuncConstant::copy()
{
    FuncConstant* cp = new FuncConstant();
    *cp = *this;

    for (unsigned i = 0; i < symbols.size(); i++) {
        symbols[i] = symbols[i]->copy();
    }

    return cp;

    //cp->symbols = new Symbol*[length];

    //cp->symbols;

//    for (unsigned i = 0; i < symbols->size(); i++) {
//        (*cp->symbols)[i] = (*symbols)[i]->copy();
//    }

//    return (Symbol*)cp;
}

FuncConstant::~FuncConstant() {
}
