#include "symbol.h"
#include "symboltable.h"

Symbol::Symbol(std::string name) {
    id = SymbolTable.getInstance()->addSymbol(name);
}

int Symbol::getID() {
    return this->id;
}

void Symbol::setID(int id) {
    this->id = id;
}

inline std::string Symbol::toString()
{
    return SymbolTable.getInstance()->getSymbol(id);
}

bool Symbol::cmp(Symbol b) {
    return b.getID() == id;
}

inline bool Symbol::isTerm()
{
    return true;
}

inline Symbol * Symbol::copy()
{
    return new Symbol(*this);
}

Symbol::~Symbol() {
}
