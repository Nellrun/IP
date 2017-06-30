#ifndef LAMBDA_H
#define LAMBDA_H

#include "symbol.h"
#include "funcconstant.h"
#include <list>
#include <string>
#include <typeinfo>
#include "symboltable.h"

struct Replace
{
    int from;
    int to;
};


class Lambda
{
public:
    Lambda();
    ~Lambda();

    std::list<Replace> getList();
    void add(int from, int to);
    std::string toString();

    int getSize();


private:
    std::list<Replace> replaceList;
};

#endif // LAMBDA_H
