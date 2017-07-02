#include "ip.h"
#include "display.h"

//Функция унификации двух предикатов
Lambda* unification(Predicate* a, Predicate* b) {

    Lambda* l = new Lambda();

    //Проверка равенства предикатов
    if (a->getID() != b->getID()) return l;
    if (a->isNegative() != b->isNegative()) return l;
    if (a->getSize() != b->getSize()) return l;

    for (int i = 0; i < a->getSize(); i++) {
        Symbol* ai = (*a->getSymbols())[i];
        Symbol* bi = (*b->getSymbols())[i];

        //Если нет переменных и литералы не равны, то унификация невозможна
        if ((typeid(*ai) != typeid(Variable)) && (typeid(*bi) != typeid(Variable)) && (!ai->cmp(*bi))) {
            return new Lambda();
        }

        if (typeid(*bi) == typeid(Variable)) {
            ai = bi;
            bi = (*a->getSymbols())[i];
        }

        if (typeid(*ai) == typeid(Variable)) {
            if (typeid(*bi) != typeid(FuncConstant)) {
                l->add(ai, bi);
            }
            else {
                if (!(((FuncConstant*)bi)->contain(ai))) {
                    l->add(ai, bi);
                }
                else {
                    return new Lambda();
                }
            }
        }
        else {
            l->add(ai, bi);
        }

    }

    return l;

}

std::vector<W*>* part_divide(Statement* b, Statement* d) {
    std::vector<W*>* res = new std::vector<W*>();

    int j = 0;
    for (auto dP : *d->getPredicates()) {
        int i = 0;
        for (auto bP : *b->getPredicates()) {
            W* w = new W();
            Lambda* l = unification(dP, bP);
            if (l->getSize() > 0) {
                w->n = b->replace(l, i);
                w->d = d->replace(l, j);
                w->q = g;

                if (w->n->getSize() == 0) {
                    w->q = 0;
                }
            }
            else {
                w->q = 1;
            }

            if (w->q == g) {
                Display::getInstance()->printLine(l->toString(), 1);
                Display::getInstance()->printLine("q = " + std::to_string(w->q) +
                                                  " b = " + w->n->toString() +
                                                  " d = " + w->d->toString(), 1);
            }
            else {
                Display::getInstance()->printLine("q = " + std::to_string(w->q), 1);
            }

            res->push_back(w);
            delete l;
            i++;
        }
        j++;
    }

    return res;
}

N* divide(std::vector<Statement*>* b, Statement* d) {
    // Общая структура для хранения текущих остатков и делителей
    N* n = new N();

    for (auto stat: *b) {
        if (stat->getSize() == 1) continue;
        W* w = new W();
        w->n = stat;
        w->d = d;
        w->q = g;
        n->w.push_back(w);
    }

    n->q = g;

    // Флаг для проверки первой итерации
    bool firstIter = true;

    while (n->q == g) {
        N* ni = new N();
        ni->q = 1;

        for (auto w: n->w) {
            if (w->q != g) {
//                Display::getInstance()->printLine("Q = " + std::to_string(w->q));
                continue;
            }

            Display::getInstance()->printLine(w->n->toString() + " / " + w->d->toString());
            std::vector<W*>* vWi = part_divide(w->n, w->d);

            for (auto wi : *vWi) {
                ni->w.push_back(wi);
            }
        }

        for (auto w : ni->w) {
            if (w->q == 0) {
                ni->q = 0;
                return ni;
            }
            if (w->q == g) {
                ni->q = g;
                break;
            }
        }

        if (firstIter) {
            firstIter = false;
            for (Statement* stat : *b) {
                if (stat->getSize() == 1) {
                    Predicate* dn = (*stat->getPredicates())[0];
                    Predicate* pn = dn->copy();
                    pn->setNegative(!pn->isNegative());
                    for (W* w : ni->w) {
                        if (w->d == NULL) continue;
                        w->d->addPredicate(pn);
                    }
                }
            }
        }

        if (ni->q == 1) {
            n->q = 1;
            return n;
        }

        n = ni;
    }

    return n;
}
