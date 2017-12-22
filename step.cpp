#include "step.h"

Step::Step()
{

}


Step::Step(Divisor* d, int depth) {
    this->d = d;
    this->depth = depth;
}
