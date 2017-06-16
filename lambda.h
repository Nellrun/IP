#ifndef LAMBDA_H
#define LAMBDA_H

#include "symbol.h"
#include "funcconstant.h"
#include <list>
#include <string>
#include <typeinfo>

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

    std::list<Replace> getList();
    void add(Symbol* from, Symbol* to);
    std::string getString();


private:
    std::list<Replace> replaceList;
};

#endif // LAMBDA_H
