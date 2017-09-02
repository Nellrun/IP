#ifndef STEP_H
#define STEP_H


class Step
{
public:
    Step();
    Step(Statement d, int depth);

    Step* sons;
    int Q;
    Statement d;
    Omega* omegas;
    int depth;
};

#endif // STEP_H
