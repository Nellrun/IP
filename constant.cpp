#include "constant.h"

Constant::Constant(std::string name) {
    this->name = name;
}

Constant::Constant(std::string name, std::string value) {
    this->name = name;
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
