#ifndef SYMBOL_H
#define SYMBOL_H


#include <string>

class Symbol
{
public:
    Symbol() {};
    Symbol(std::string name);
    ~Symbol();

    virtual int getID();
    virtual void setID(int id);
    virtual std::string toString();
    virtual bool cmp(Symbol b);
    virtual bool isTerm();
    virtual Symbol* copy();

protected:
    int id;
};

#endif // SYMBOL_H
