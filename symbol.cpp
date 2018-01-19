#include "symbol.h"

Symbol::Symbol(std::string name) {
    this->id = SymbolTable::getInstance()->addSymbol(name);
    this->level = 0;
    this->index = 1;
}

int Symbol::getID() {
    return this->id;
}

int Symbol::getLevel() {
    return this->level;
}

void Symbol::setLevel(int lvl)
{
    this->level = lvl;
}

int Symbol::getIndex() {
    return this->index;
}

int Symbol::setIndex(int ind)
{
    this->index = ind;
}

void Symbol::setID(int id) {
    this->id = id;
}

std::string Symbol::toString()
{
    if (level > 1) {
        return SymbolTable::getInstance()->getSymbol(id) + "." + std::to_string(level) + std::to_string(index);
    }
    return SymbolTable::getInstance()->getSymbol(id);
}

bool Symbol::cmp(Symbol b) {
    return ((b.getID() == this->id) && (b.getLevel() == this->level) && (b.getIndex() == this->index));
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
