#include "statement.h"

Statement::Statement()
{
}

void Statement::addLiteral(Predicate* p) {
    literals.push_back(p);
//    return this;
}

std::vector<Predicate*>* Statement::getLiterals() {
    return &literals;
}

int Statement::getSize() {
    return literals.size();
}

bool Statement::isEqual(Statement *b)
{
    if (literals.size() != b->getSize()) return false;

    for (int i = 0; i < literals.size(); i++) {
        Predicate* p = (*b->getLiterals())[i];
        if (p->isNegative() != literals[i]->isNegative()) return false;
        if (!literals[i]->isEqual(p)) return false;
    }

    return true;
}

Statement* Statement::replace(Lambda *l, int id = -1) {
    Statement* s = new Statement();


    int i = 0;
    for (auto p : literals) {
        if (i == id) {
            i++;
            continue;
        }
        s->addLiteral(p->copy());
        i++;
    }

    for (auto elem : l->getList()) {
        for (int i = 0; i < s->literals.size(); i++) {
            s->literals[i]->replace(elem->from, elem->to);
        }
    }

    return s;
}

Statement* Statement::copy(bool inverse) {
    Statement* s = new Statement();

    for (auto p : literals) {
        Predicate* pn = p->copy();
        if (inverse) {
            pn->setNegative(!pn->isNegative());
        }
        s->addLiteral(pn);
    }

    return s;
}

void Statement::setLevel(int lvl, int ind)
{
    for (auto p: literals) {
        p->setLevel(lvl, ind);
    }
}

std::string Statement::toString(bool beauty) {
    std::string out;
    if (beauty)
        out = "1 -> ";
    else
        out = "";

    for (unsigned i = 0; i < literals.size(); i++) {
        if (i != literals.size() - 1) {
            out += literals[i]->toString() + " or ";
        }
        else {
            out += literals[i]->toString();
        }
    }

    if (beauty)
        out += ".";

    return out;
}
