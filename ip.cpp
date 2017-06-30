#include "ip.h"

//Функция унификации двух предикатов
Lambda* unification(Predicate* a, Predicate* b) {

    Lambda* l = new Lambda();

    //Проверка равенства предикатов
    if (a->getID() != b->getID()) return l;
    if (a->isNegative() != b->isNegative()) return l;
    if (a->getSize() != b->getSize()) return l;

    for (int i = 0; i < a->getSize(); i++) {
        Symbol* ai = &(*a->getSymbols())[i];
        Symbol* bi = &(*b->getSymbols())[i];

        //Если нет переменных и литералы не равны, то унификация невозможна
        if ((typeid(*ai) != typeid(Variable)) && (typeid(*bi) != typeid(Variable)) && (!ai->cmp(*bi))) {
            return new Lambda();
        }

        if (typeid(*bi) == typeid(Variable)) {
            ai = bi;
            bi = &(*a->getSymbols())[i];
        }

        if (typeid(*ai) == typeid(Variable)) {
            if (typeid(*bi) != typeid(FuncConstant)) {
                l->add(ai->getID(), bi->getID());
            }
            else {
                if (!(((FuncConstant*)bi)->contain(ai))) {
                    l->add(ai->getID(), bi->getID());
                }
                else {
                    return new Lambda();
                }
            }
        }

    }

    return l;

}

std::vector<W*>* part_divide(Statement* b, Statement* d) {
    std::vector<W*>* res = new std::vector<W*>();

    for (Predicate dP : *d->getPredicates()) {
        for (Predicate bP : *b->getPredicates()) {
            W* w = new W();
            Lambda* l = unification(&bP, &dP);
            if (l->getSize() > 0) {
//                w->n =
            }
            else {
                w->q = 1;
            }

            res->push_back(w);
            delete l;
        }
    }

    return res;
}

//std::list<W> w_operation(Predicate** D, int sizeD, Predicate** d, int sized) {
//    std::list<W> out;

//    for (int i = 0; i < sizeD; i++) {
//        for (int j = 0; j < sized; j++) {
//            Lambda* l = unification(D[i], d[j]);

//            W w;
//            w.l = l;

//            if (l == NULL) {
//                w.q = 1;
//                out.push_back(w);
//                continue;
//            }

//            w.sizeB = sizeD - 1;
//            w.sizeD = sized;

//            if (w.sizeB == 0) w.q = 0;
//            else w.q = g;

//            w.b = new Predicate*[w.sizeB];
//            w.d = new Predicate*[w.sizeD];

//            int s = 0;
//            for (int k = 0; k < sizeD; k++) {
//                if (k == i) continue;

//                w.b[s] = D[k]->copy();
//                s++;
//            }

//            for (int k = 0; k < sized; k++) {
//                w.d[k] = d[k]->copy();
//            }

//            out.push_back(w);
//        }
//    }


//    return out;
//}
