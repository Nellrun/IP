#include "predicate.h"

Predicate::Predicate(std::string name, std::vector<Symbol*>* symbols, bool negative = false)
{
    this->name = name;
    this->negative = negative;
    this->symbols = symbols;
}

Predicate::Predicate(std::string name, bool negative = false) {
    this->name = name;
    this->negative = negative;
}

bool Predicate::isNegative() {
    return negative;
}

std::string Predicate::getString()
{
    std::string out = this->name + "(";
    for (unsigned i = 0; i < symbols->size() - 1; i++) {
        out += (*symbols)[i]->getString() + ", ";
    }
    out += (*symbols)[symbols->size() - 1]->getString() + ")";

    return negative ? "!" + out : out;
}

std::vector<Symbol*>* Predicate::getSymbols()
{
    return symbols;
}

int Predicate::getSize()
{
    return symbols->size();
}

std::string Predicate::getName()
{
    return name;
}

Predicate* Predicate::copy()
{
    Predicate* p = new Predicate(*this);
    //p->symbols = new Symbol*[length];

    //for (int i = 0; i < length; i++) {
    //	p->symbols[i] = symbols[i]->copy();
    //}

    return p;
}

Predicate::~Predicate()
{
}
