#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <string>

class SymbolTable
{
public:
    SymbolTable();

    int addSymbol(std::string name);
    std::string getSymbol(int id);
    static SymbolTable* getInstance() {
        if (instance == NULL) {
            instance = new SymbolTable();
        }

        return instance;
    }

private:
    std::vector<std::string> names;
    static SymbolTable* instance;
};

#endif // SYMBOLTABLE_H
