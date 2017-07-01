#include "predicate.h"

Predicate::Predicate() {

}

Predicate::Predicate(std::string name, std::vector<Symbol*> *symbols, bool negative) {
    id = SymbolTable::getInstance()->addSymbol(name);
    this->negative = negative;
    this->symbols = *symbols;
}

Predicate::Predicate(std::string name, bool negative = false) {
    id = SymbolTable::getInstance()->addSymbol(name);
    this->negative = negative;
}

void Predicate::setNegative(bool l) {
    negative = l;
}

bool Predicate::isNegative() {
    return negative;
}

std::string Predicate::toString()
{
    std::string out = SymbolTable::getInstance()->getSymbol(id) + "(";
    for (unsigned i = 0; i < symbols.size() - 1; i++) {
        out += symbols[i]->toString() + ", ";
    }
    out += symbols[symbols.size() - 1]->toString() + ")";

    return negative ? "not " + out : out;
}

Predicate* Predicate::addSymbol(Symbol* s) {
    symbols.push_back(s);
    return this;
}

//std::vector<Symbol>* Predicate::getSymbols()
//{
//    return &symbols;
//}

//int Predicate::getSize()
//{
//    return symbols.size();
//}

//std::string Predicate::getName()
//{
//    return name;
//}

Predicate* Predicate::copy()
{
    Predicate* p = new Predicate();
    *p = *this;

    for (unsigned i = 0; i < symbols.size(); i++) {
        symbols[i] = symbols[i]->copy();
    }

    return p;
}

Predicate::~Predicate()
{
}
