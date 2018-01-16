#include "divisor.h"

Divisor::Divisor()
{

}

Divisor::Divisor(Statement *s) {
    for (Predicate* p: *s->getLiterals()) {
        d* elem = new d();
        elem->lambda = Lambda();
        elem->literal = *p->copy();
        literals.push_back(elem);
    }
}

void Divisor::addLiteral(Predicate *p, Lambda *l)
{
    d* newElem = new d();
    newElem->literal = *p->copy();
    newElem->lambda = *l->copy();
    literals.push_back(newElem);
}

Divisor *Divisor::copy()
{
    Divisor* divisor = new Divisor();

    for (d* elem: literals) {
        d* newElem = new d();
        newElem->literal = *elem->literal.copy();
        newElem->lambda = *elem->lambda.copy();

        divisor->literals.push_back(newElem);
    }

    return divisor;
}

std::string Divisor::toString(bool beauty)
{
    std::string out;
    if (beauty)
        out = "1 -> ";
    else
        out = "";

    for (unsigned i = 0; i < literals.size(); i++) {
        if (i != literals.size() - 1) {
            out += literals[i]->literal.toString() + " or ";
        }
        else {
            out += literals[i]->literal.toString();
        }
    }

    if (beauty)
        out += ".";

    return out;
}

Divisor* Divisor::replace(Lambda* l, int k) {
    int i = 0;
    Divisor* divisor = new Divisor();

    for (d* elem: literals) {
        if (i == k) {
            i++;
            continue;
        }

        d* newElem = new d();
        newElem->literal = *elem->literal.copy();

        for (auto elem : l->getList()) {
                newElem->literal.replace(elem->from, elem->to);
        }

        newElem->lambda.extend(l);

        divisor->literals.push_back(newElem);
    }

    return divisor;
}
