#ifndef LAMBDA_H
#define LAMBDA_H

#include "symbol.h"
#include "funcconstant.h"
#include "variable.h"
#include <list>
#include <string>
#include <typeinfo>
#include "symboltable.h"

struct Replace
{
    Symbol* from;
    Symbol* to;
};


class Lambda
{
public:
    Lambda();
    ~Lambda();

    std::vector<Replace*> getList();
    void add(Symbol* from, Symbol* to);
    std::string toString();
    Symbol* getReplace(Symbol* s);

    void extend(Lambda* l);
    Lambda* copy();

    int getSize();


private:
    std::vector<Replace*> replaceList;
};

#endif // LAMBDA_H
