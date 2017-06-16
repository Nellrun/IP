#include "lambda.h"

Lambda::Lambda()
{
}

Lambda::~Lambda()
{
}

inline std::list<Replace> Lambda::getList()
{
    return replaceList;
}

inline void Lambda::add(Symbol* from, Symbol* to)
{
    //bool a = typeid(*from) == typeid(*to);
    //bool b = typeid(*from) == typeid(Variable);

    Replace r;
    r.from = from->copy();
    r.to = to->copy();
    replaceList.push_back(r);

    for (std::list<Replace>::iterator iter = replaceList.begin(); iter != replaceList.end(); iter++) {
        if (typeid(*((*iter).to)) == typeid(FuncConstant)) {
            ((FuncConstant*)((*iter).to))->replace(r.from, r.to);
        }
    }
}

inline std::string Lambda::getString()
{
    std::string out = "{";
    for (std::list<Replace>::iterator iter = replaceList.begin(); iter != replaceList.end(); iter++) {
        out += (*iter).to->getString() + "/" + (*iter).from->getString() + ",";
    }
    out += "}";
    return out;
}
