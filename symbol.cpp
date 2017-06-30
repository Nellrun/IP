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
    return b.getID() == id;
}

bool Symbol::isTerm()
{
    return true;
}

Symbol * Symbol::copy()
{
    return new Symbol(*this);
}

Symbol::~Symbol() {
}
