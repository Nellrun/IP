#include "symbol.h"

Symbol::Symbol(std::string name) {
    this->name = name;
}

std::string Symbol::getName() {
    return this->name;
}

void Symbol::setName(std::string name) {
    this->name = name;
}

inline std::string Symbol::getString()
{
    return name;
}

bool Symbol::cmp(Symbol b) {
    //if (typeid(*this) != typeid(b)) return false;
    if (name != b.getName()) return false;
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
