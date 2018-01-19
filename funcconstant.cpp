#include "funcconstant.h"

#include <typeinfo>

FuncConstant::FuncConstant() {
    this->level = 0;
    this->index = 1;
}

FuncConstant::FuncConstant(std::string name) {
   id = SymbolTable::getInstance()->addSymbol(name);
   this->level = 0;
   this->index = 1;
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

void FuncConstant::setLevel(int lvl, int ind)
{
    for (auto elem: symbols) {
        if (typeid(*elem) == typeid(FuncConstant)) {
            ((FuncConstant*) (elem))->setLevel(lvl, ind);
        }
        if (typeid(*elem) == typeid(Variable)) {
            elem->setLevel(lvl);
            elem->setIndex(ind);
        }
    }
}

bool FuncConstant::isEqual(FuncConstant *b)
{
    if (!this->cmp(*b)) return false;
    if (symbols.size() != b->getSize()) return false;
    for (int i = 0; i < symbols.size(); i++) {
        symbols[i]->cmp(*(*b->getSymbols())[i]);
//        if (!symbols[i]->cmp((*(b->getSymbols())[i]))) return false;
//        if (symbols[i]->getID() != b->getSymbols()[i]->getID()) return false;
        if (typeid(*symbols[i]) == typeid(FuncConstant)) {
            if (! ((FuncConstant*) symbols[i])->isEqual((FuncConstant *) (*b->getSymbols())[i])) return false;
        }
    }

    return true;
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
        if (typeid(*symbols[i]) == typeid(FuncConstant)) {
            ((FuncConstant*) symbols[i])->replace(from, to);
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
