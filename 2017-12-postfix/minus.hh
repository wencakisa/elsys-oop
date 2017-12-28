#ifndef MINUS_HH_
#define MINUS_HH_

#include "binary.hh"

class Minus : public BinaryOperation {
public:
    Minus(Calculator& calculator);

    double execute(double value1, double value2) const;
};

#endif /* end of include guard: MINUS_HH_ */
