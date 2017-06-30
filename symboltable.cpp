#include "symboltable.h"

SymbolTable::SymbolTable()
{

}

static SymbolTable* SymbolTable::getInstance() {
    if (instance == NULL) {
        instance = new SymbolTable();
    }

    return instance;
}

int SymbolTable::addSymbol(std::string name) {
    names.push_back(name);
    return names.size();
}

std::string SymbolTable::getSymbol(int id) {
    return names[id];
}
