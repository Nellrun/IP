#include "statement.h"

Statement::Statement()
{
}

Statement* Statement::addPredicate(Predicate* p) {
    predicates.push_back(*p);
    return this;
}

std::vector<Predicate>* Statement::getPredicates() {
    return &predicates;
}

std::string Statement::toString() {
    std::string out = "1 -> ";

//    for (Predicate* p : *predicates) {
//        out += p->toString() + " or ";
//    }

    for (unsigned i = 0; i < predicates.size(); i++) {
        if (i != predicates.size() - 1) {
            out += predicates[i].toString() + " or ";
        }
        else {
            out += predicates[i].toString();
        }
    }

    out += ".";

    return out;
}
