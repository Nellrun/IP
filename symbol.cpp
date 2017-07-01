#include "symbol.h"

Symbol::Symbol(std::string name) {
    this->id = SymbolTable::getInstance()->addSymbol(name);
}

int Symbol::getID() {
    return this->id;
}

void Symbol::setID(int id) {
    this->id = id;
}

std::string Symbol::toString()
{
    return SymbolTable::getInstance()->getSymbol(id);
}

bool Symbol::cmp(Symbol b) {
    return b.getID() == this->id;
}

bool Symbol::isTerm()
{
    return true;
}

Symbol * Symbol::copy()
{
    Symbol* s = new Symbol();
    *s = *this;
    return s;
}

Symbol::~Symbol() {
}
