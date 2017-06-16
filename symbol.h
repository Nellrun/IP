#ifndef SYMBOL_H
#define SYMBOL_H


#include <string>

class Symbol
{
public:
    Symbol() {};
    Symbol(std::string name);
    ~Symbol();

    virtual std::string getName();
    virtual void setName(std::string);
    virtual std::string getString();
    virtual bool cmp(Symbol b);
    virtual bool isTerm();
    virtual Symbol* copy();

protected:
    std::string name;
};

#endif // SYMBOL_H
