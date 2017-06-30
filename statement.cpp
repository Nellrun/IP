#include "statement.h"

Statement::Statement()
{
}

Statement* Statement::addPredicate(Predicate* p) {
    predicates.push_back(p);
    return this;
}

std::vector<Predicate*>* Statement::getPredicates() {
    return &predicates;
}

Statement* Statement::replace(Lambda *l, int id = -1) {
    Statement* s = new Statement();


    int i = 0;
    for (auto p : predicates) {
        if (i == id) continue;
        s->addPredicate(p->copy());
        i++;
    }

    for (auto elem : l->getList()) {
        for (int i = 0; i < s->predicates.size(); i++) {
            s->predicates[i]->replace(elem.to, elem.from);
        }
    }

    return s;
}

std::string Statement::toString() {
    std::string out = "1 -> ";

//    for (Predicate* p : *predicates) {
//        out += p->toString() + " or ";
//    }

    for (unsigned i = 0; i < predicates.size(); i++) {
        if (i != predicates.size() - 1) {
            out += predicates[i]->toString() + " or ";
        }
        else {
            out += predicates[i]->toString();
        }
    }

    out += ".";

    return out;
}
