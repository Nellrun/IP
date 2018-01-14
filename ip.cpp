#include "ip.h"
#include "display.h"
#include <stack>

//Функция унификации двух предикатов
Lambda* unification(FuncConstant* a, FuncConstant* b) {

    Lambda* l = new Lambda();

    //Проверка равенства предикатов
    if (a->getID() != b->getID()) return NULL;
    if ( (typeid(*a) == typeid(Predicate)) && ((Predicate*) a)->isNegative() != ((Predicate*) b)->isNegative()) return NULL;
    if (a->getSize() != b->getSize()) return NULL;

    for (int i = 0; i < a->getSize(); i++) {
        Symbol* ai = (*a->getSymbols())[i];
        Symbol* bi = (*b->getSymbols())[i];

        //Если нет переменных и литералы не равны, то унификация невозможна
        if ((typeid(*ai) != typeid(Variable)) && (typeid(*bi) != typeid(Variable)) && (!ai->cmp(*bi))) {
            return NULL;
        }

        if (typeid(*bi) == typeid(Variable)) {
            ai = bi;
            bi = (*a->getSymbols())[i];
        }

        if (typeid(*ai) == typeid(Variable)) {
            Symbol* to = l->getReplace(ai);

            // Если переменная присваивается 2 раза константе
            if ((to != NULL) && (typeid(*(to)) != typeid(Variable)) && (typeid(*bi) != typeid(Variable)) ) {
                delete l;
                return NULL;
            }

            if (typeid(*bi) != typeid(FuncConstant)) {
                l->add(ai, bi);
            }
            else {
                if (!(((FuncConstant*)bi)->contain(ai))) {
                    l->add(ai, bi);
                }
                else {
                    return NULL;
                }
            }
        }
        else {
            if (typeid(*ai) == typeid(FuncConstant)) {
                Lambda* u = unification((FuncConstant*)ai, (FuncConstant*)bi);
                if (u == NULL) return NULL;
                l->extend(u);
            }
        }
//        else {
//            l->add(ai, bi);
//        }

    }

    return l;

}

WType* part_divide(StatementLambda* b, Divisor* d) {
//    std::vector<W*>* res = new std::vector<W*>();
    WType* res = new WType();
    res->q = 1;
    res->b = *b;
    res->d = *d;

    int j = 0;
    for (auto dP : *d->getLiterals()) {
        int i = 0;
        for (auto bP : *b->b->getLiterals()) {
            W* w = new W();
            Lambda* l = unification((FuncConstant*) dP, (FuncConstant*) bP);
            if (l != NULL) {
                w->n = new StatementLambda();
                w->n->b = b->b->replace(l, i);
                w->n->l = b->l->copy();
                w->n->l->extend(l);
                w->d = d->replace(l, j);

//                Display::getInstance()->printLine(w->n->b->toString(), 1);

                res->n.push_back(w);

                if (w->n->b->getSize() == 0) {
                    Lambda* lc = w->n->l->copy();
                    lc->extend(&dP->lambda);
                    res->r.push_back(lc);
                }

                if (w->n->b->getSize() > 0) {
                    res->q = g;
                }
                else {
                    if (res->q != g) res->q = 0;
                }
            }
            i++;
        }
        j++;
    }

    return res;
}

Omega* takeDivision(std::vector<StatementLambda*> facts, StatementLambda* D, Divisor* d) {
    Omega* res = new Omega();
    res->D = *D;

    // Первое частичное деление
    WType* firstDivide = part_divide(D, d);
    res->ws.push_back(firstDivide);


    // Добавление остатков в массив (для удобства)
    for (W* elem : firstDivide->n) {
        res->n.push_back(elem);
    }

    if (firstDivide->q != g) {
        res->q = firstDivide->q;
        return res;
    }

    std::stack<WType*> vc;

    for (W* elem : firstDivide->n) {

        // Выполнение второго шага полного деления
        // Добавление инверсий литералов фактов
        if (elem->n->b->getSize() > 0) {
            for (StatementLambda* s : facts) {
                Predicate* f = (*s->b->getLiterals())[0]->copy();
                f->setNegative(!f->isNegative());
                elem->d->addLiteral(f, s->l);
            }
            WType* a = part_divide(elem->n, elem->d);

            // Добавление остатков
            for (W* elem : a->n) {
                res->n.push_back(elem);
            }

            if (a->q == g) {
                vc.push(a);
            }
            res->ws.push_back(a);
        }
    }

    while (!vc.empty()) {
        WType* topElem = vc.top();
        vc.pop();

        for (W* elem : topElem->n) {

            // Выполнение второго шага полного деления
            if (elem->n->b->getSize() > 0) {
                WType* a = part_divide(elem->n, elem->d);

                // Добавление остатков
                for (W* elem : a->n) {
                    res->n.push_back(elem);
                }

                if (a->q == g) {
                    vc.push(a);
                }
                res->ws.push_back(a);
            }
        }
    }

    return res;
}

//bool isAbsorption(StatementLambda* a, std::vector<StatementLambda*>* e) {
//    for (StatementLambda* elem: e) {
//        if (a->b->getSize() != elem->b->getSize()) continue;

//        for (int i = 0; i < a->b->getSize(); i++) {
//            Predicate* ai = a->b->getLiterals()[i];
//            Predicate* bi = elem->b->getLiterals()[i];

//            if (ai->getID() != bi->getID()) break;
//            if (ai->isNegative() != bi->isNegative()) break;

//        }
//    }

//    return false;
//}

Step* takeStep(std::vector<StatementLambda*> D, Divisor* d, Step* parent) {
    Step* step = new Step();
    if (parent != NULL)
        step->depth = parent->depth + 1;

    std::vector<StatementLambda*> facts;

    for (StatementLambda* s : D) {
        if (s->b->getSize() == 1) facts.push_back(s);
    }

    std::vector<StatementLambda*> e;

    for (StatementLambda* s: D) {
        if (s->b->getSize() > 1) {
            // Выполнение полного деления
            Display::getInstance()->printLine(s->b->toString() + " // " + d->toString());
            Omega* omega = takeDivision(facts, s, d);
            step->omegas.push_back(omega);
//            for (WType* elem : w->ws) {
//                for ( W* w : elem->n ) {
//                    if (w->n->b->getSize() > 0) {
//                        Display::getInstance()->printLine(w->n->b->toString() + " " + w->n->l->toString(), 1);
//                        e.push_back(w->n);
//                        step->c.push_back(w->n);
//                    }
//                    else {
//                        Display::getInstance()->printLine("0 " + w->n->l->toString(), 1);
//                    }

//                }
//            }
            for (W* w: omega->n) {
                if (w->n->b->getSize() > 0) {
                    Display::getInstance()->printLine(w->n->b->toString() + " " + w->n->l->toString(), 1);
                    e.push_back(w->n);
                    step->c.push_back(w->n);
                }
                else {
                    Display::getInstance()->printLine("0 " + w->n->l->toString(), 1);
                }
            }
        }
    }

    std::vector<Divisor*> divisors;
    divisors.push_back(new Divisor());

    for (StatementLambda* sl : e) {
        // Расширяем количество выводимых высказываний
        int divisorsSz = divisors.size();
        for (int k = 0; k < (sl->b->getSize() - 1); k++) {
            for (int i = 0; i < divisorsSz; i++) {
                divisors.push_back(divisors[i]->copy());
            }
        }

        int i = 0;
        for (Divisor* elem: divisors) {
            int k = i++ / divisorsSz;
            Predicate* newP = (*sl->b->getLiterals())[k]->copy();
            newP->setNegative(!newP->isNegative());
            elem->addLiteral(newP, sl->l->copy());
        }
    }

    // фиксирование результатов
    step->d = d;
    step->m = divisors;
    step->p = 0;

    if (e.size() == 0) {
        step->p = 1;
    }

    return step;
}

Step *conclusion(std::vector<StatementLambda*> D, Divisor* d, int depth, Step *parent)
{
    Step* root = NULL;
    if (parent == NULL) {
        //Вызов процедуры шага
        root = takeStep(D, d, NULL);
        root->depth = 1;
    }
    else {
        if (parent->depth == depth) {
            return NULL;
        }
        root = takeStep(D, d, parent);
    }

    if (root == NULL) return NULL;

    for (Divisor* di : root->m) {
        Step* si = conclusion(D, di, depth, root);
        if (si != NULL)
            root->sons.push_back(si);
        si = conclusion(root->c, di, depth, root);
        if (si != NULL)
            root->sons.push_back(si);
    }

    return root;
}
