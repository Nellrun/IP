#include "variable.h"

Variable::Variable(std::string name) {
    id = SymbolTable::getInstance()->addSymbol(name);
    this->level = 0;
    this->index = 1;
}

Symbol * Variable::copy()
{
    return (Symbol*) new Variable(*this);
}

Variable::~Variable() {
}
