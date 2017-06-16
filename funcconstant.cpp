#include "funcconstant.h"

FuncConstant::FuncConstant(std::string name) {
    this->name = name;
}

FuncConstant::FuncConstant(std::string name, std::vector<Symbol*> *symbols) {
    this->name = name;
    this->negative = negative;
    this->symbols = symbols;
}

std::string FuncConstant::getString() {
    std::string out = this->name + "(";
    for (unsigned i = 0; i < symbols->size() - 1; i++) {
        out += (*symbols)[i]->getString() + ", ";
    }

    //for (auto &elem : symbols) {
    //	out += elem->getString() + ", ";
    //}

    out += (*symbols)[symbols->size() - 1]->getString() + ")";

    return out;
}

inline std::vector<Symbol*>* FuncConstant::getSymbols()
{
    return symbols;
}

inline void FuncConstant::setSymbols(std::vector<Symbol*> *s)
{
    this->symbols = s;
}

inline void FuncConstant::replace(Symbol* from, Symbol* to)
{
    for (unsigned i = 0; i < symbols->size(); i++) {
        if ((*symbols)[i]->cmp(*from)) {
            (*symbols)[i] = to;
        }
        if (typeid((*(*symbols)[i])) == typeid(FuncConstant)) {
            ((FuncConstant*)(*symbols)[i])->replace(from, to);
        }
    }
}

inline bool FuncConstant::contain(Symbol * s)
{
    for (unsigned i = 0; i < symbols->size(); i++) {
        if ((*symbols)[i]->cmp(*s)) return true;
        if ((typeid(symbols[i]) == typeid(FuncConstant)) && (((FuncConstant*)(*symbols)[i])->contain(s))) return true;
    }
    return false;
}

inline Symbol * FuncConstant::copy()
{
    FuncConstant* cp = new FuncConstant(*this);

    //cp->symbols = new Symbol*[length];

    //cp->symbols;

    for (unsigned i = 0; i < symbols->size(); i++) {
        (*cp->symbols)[i] = (*symbols)[i]->copy();
    }

    return (Symbol*)cp;
}

FuncConstant::~FuncConstant() {
}
