#include "lambda.h"

Lambda::Lambda()
{
}

Lambda::~Lambda()
{
}

std::list<Replace*> Lambda::getList()
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

    Replace* r = new Replace();
    r->from = from->copy();
    r->to = to->copy();

    if (typeid(*to) == typeid(Variable)) {
        Symbol* a = to;
        while ( (a != NULL) && (typeid(*a) == typeid(Variable)) ) {
            r->to = a;
            a = this->getReplace(a);
        }

        if (a != NULL) {
            r->to = a->copy();
        }
        else {
            r->to = r->to->copy();
        }
    }

    for (Replace* i : replaceList) {
        if (i->to->getID() == r->from->getID()) {
            i->to = r->to->copy();
        }
    }

    replaceList.push_back(r);

    for (Replace* elem: replaceList) {
        if (typeid(*(elem->to)) == typeid(FuncConstant)) {
            ((FuncConstant*) elem->to)->replace(r->from, r->to);
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

//    for (std::list<Replace>::iterator iter = replaceList.begin(); iter != replaceList.end(); iter++) {
//        out += (*iter).to->toString() + "/" + (*iter).from->toString() + ",";
//    }

    for (Replace* elem: replaceList) {
        out += elem->to->toString() + "/"
                + elem->from->toString() + ",";
    }

    out += "}";
    return out;
}

Symbol* Lambda::getReplace(Symbol *s)
{

    for (Replace* r: replaceList) {
        if (r->from->cmp(*s)) return r->to;
    }

    return NULL;
}

void Lambda::extend(Lambda *l)
{
    for (Replace* elem : l->getList()) {
        this->add(elem->from, elem->to);
    }
}

Lambda *Lambda::copy()
{
    Lambda* l = new Lambda();
    for (auto elem: replaceList) {
        Replace* newElem = new Replace();
        newElem->from = elem->from->copy();
        newElem->to = elem->to->copy();
        l->replaceList.push_back(newElem);
    }

    return l;
}
