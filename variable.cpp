#include "variable.h"

Variable::Variable(std::string name) {
    id = SymbolTable::getInstance()->addSymbol(name);
}

Symbol * Variable::copy()
{
    return (Symbol*) new Variable(*this);
}

Variable::~Variable() {
}
