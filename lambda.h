#ifndef LAMBDA_H
#define LAMBDA_H

#include "Symbol.h"
#include "FuncConstant.h"
#include <list>
#include <string>

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
