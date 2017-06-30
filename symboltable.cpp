#include "symboltable.h"

SymbolTable* SymbolTable::instance = NULL;

SymbolTable::SymbolTable()
{

}

//SymbolTable* SymbolTable::getInstance() {
//    if (instance == NULL) {
//        instance = new SymbolTable();
//    }

//    return instance;
//}

int SymbolTable::addSymbol(std::string name) {

    for (int i = 0; i < names.size(); i++) {
        if (name.compare(names[i]) == 0) {
            return i;
        }
    }

    names.push_back(name);
    return names.size() - 1;
}

std::string SymbolTable::toString() {
    std::string out = "";
    int i = 0;
    for (auto elem : names) {
        out += std::to_string(i) + "\t" + elem + "\n";
        i++;
    }

    return out;
}

std::string SymbolTable::getSymbol(int id) {
    return names[id];
}
