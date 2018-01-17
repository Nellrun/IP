#include "constant.h"

Constant::Constant(std::string name) {
    id = SymbolTable::getInstance()->addSymbol(name);
    this->level = 0;
    this->index = 1;
}

Constant::Constant(std::string name, std::string value) {
    id = SymbolTable::getInstance()->addSymbol(name);
    this->value = value;
}

std::string Constant::getValue() {
    return this->value;
}

void Constant::setValue(std::string value) {
    this->value = value;
}

Symbol * Constant::copy()
{
    return (Symbol*) new Constant(*this);
}

Constant::~Constant()
{
}
