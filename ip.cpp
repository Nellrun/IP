#include "ip.h"

//Функция унификации двух предикатов
Lambda* unification(Predicate* a, Predicate* b) {
    //Проверка равенства предикатов
    if (a->getName() != b->getName()) return NULL;
    if (a->isNegative() != b->isNegative()) return NULL;
    if (a->getSize() != b->getSize()) return NULL;

    Lambda* l = new Lambda();

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

    }

    return l;

}

std::list<W> w_operation(Predicate** D, int sizeD, Predicate** d, int sized) {
    std::list<W> out;

    for (int i = 0; i < sizeD; i++) {
        for (int j = 0; j < sized; j++) {
            Lambda* l = unification(D[i], d[j]);

            W w;
            w.l = l;

            if (l == NULL) {
                w.q = 1;
                out.push_back(w);
                continue;
            }

            w.sizeB = sizeD - 1;
            w.sizeD = sized;

            if (w.sizeB == 0) w.q = 0;
            else w.q = g;

            w.b = new Predicate*[w.sizeB];
            w.d = new Predicate*[w.sizeD];

            int s = 0;
            for (int k = 0; k < sizeD; k++) {
                if (k == i) continue;

                w.b[s] = D[k]->copy();
                s++;
            }

            for (int k = 0; k < sized; k++) {
                w.d[k] = d[k]->copy();
            }

            out.push_back(w);
        }
    }


    return out;
}
