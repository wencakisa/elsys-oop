#ifndef MULTIPLY_HH_
#define MULTIPLY_HH_

#include "binary.hh"

class Multiply : public BinaryOperation {
public:
    Multiply(Calculator& calculator);

    double execute(double value1, double value2) const;
};

#endif /* end of include guard: MULTIPLY_HH_ */
