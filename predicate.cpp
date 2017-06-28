#include "predicate.h"

Predicate::Predicate(std::string name, std::vector<Symbol*>* symbols, bool negative = false)
{
    this->name = name;
    this->negative = negative;
    this->symbols = *symbols;
}

Predicate::Predicate(std::string name, bool negative = false) {
    this->name = name;
    this->negative = negative;
}

bool Predicate::isNegative() {
    return negative;
}

std::string Predicate::toString()
{
    std::string out = this->name + "(";
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

std::vector<Symbol*>* Predicate::getSymbols()
{
    return &symbols;
}

int Predicate::getSize()
{
    return symbols.size();
}

std::string Predicate::getName()
{
    return name;
}

Predicate* Predicate::copy()
{
    Predicate* p = new Predicate(*this);
    return p;
}

Predicate::~Predicate()
{
}
