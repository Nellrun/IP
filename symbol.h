#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "symboltable.h"

class Symbol
{
public:
    Symbol() {}
    Symbol(std::string name);
    ~Symbol();

    virtual int getID();
    virtual void setID(int id);
    virtual int getLevel();
    virtual void setLevel(int lvl);
    virtual int getIndex();
    virtual int setIndex(int ind);
    virtual std::string toString();
    virtual bool cmp(Symbol b);
    virtual bool isTerm();
    virtual Symbol* copy();

protected:
    int id;
    int level = 0;
    int index = 1;
};

#endif // SYMBOL_H
