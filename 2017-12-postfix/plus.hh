#ifndef PLUS_HH_
#define PLUS_HH_

#include "binary.hh"

class Plus : public BinaryOperation {
public:
    Plus(Calculator& calculator);

    double execute(double value1, double value2) const;
};

#endif
