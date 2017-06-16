#include "variable.h"

Variable::Variable(std::string name) {
    this->name = name;
}

Symbol * Variable::copy()
{
    return (Symbol*) new Variable(*this);
}

Variable::~Variable() {
}
