#include "lambda.h"

Lambda::Lambda()
{
}

Lambda::~Lambda()
{
}

std::list<Replace> Lambda::getList()
{
    return replaceList;
}

int Lambda::getSize() {
    return replaceList.size();
}

void Lambda::add(Symbol* from, Symbol* to)
{
    //bool a = typeid(*from) == typeid(*to);
    //bool b = typeid(*from) == typeid(Variable);

    Replace r;
    r.from = from->copy();
    r.to = to->copy();
    replaceList.push_back(r);

    for (Replace elem: replaceList) {
        if (typeid(*(elem.to)) == typeid(FuncConstant)) {
            ((FuncConstant*) elem.to)->replace(r.from, r.to);
        }
    }

//    for (std::list<Replace>::iterator iter = replaceList.begin(); iter != replaceList.end(); iter++) {
//        if (typeid(*((*iter).to)) == typeid(FuncConstant)) {
//            ((FuncConstant*)((*iter).to))->replace(r.from, r.to);
//        }
//    }
}

std::string Lambda::toString()
{
    if (replaceList.size() == 0) return "1";

    std::string out = "{";

    for (Replace elem: replaceList) {
        out += elem.to->toString() + "/"
                + elem.from->toString() + ",";
    }

    out += "}";
    return out;
}
