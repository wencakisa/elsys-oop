#ifndef SQRT_HH_
#define SQRT_HH_

#include "unary.hh"

class Sqrt : public UnaryOperation {
public:
    Sqrt(Calculator& calculator);

    double execute(double value) const;
};

#endif
