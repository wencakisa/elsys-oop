#ifndef LITERAL_HH_
#define LITERAL_HH_

#include "operation.hh"

class Literal : public Operation {
    double val_;
public:
    Literal(Calculator& calculator, double val);

    void eval();
};

#endif /* end of include guard: LITERAL_HH_ */
