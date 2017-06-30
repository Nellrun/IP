#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>

class SymbolTable
{
public:
    SymbolTable();

    int addSymbol(std::string name);
    std::string getSymbol(int id);
    static SymbolTable* getInstance();

private:
    std::vector<std::string> names;
    SymbolTable* instance;
};

#endif // SYMBOLTABLE_H
