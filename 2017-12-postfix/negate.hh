#ifndef NEGATE_HH_
#define NEGATE_HH_

#include "unary.hh"

class Negate : public UnaryOperation {
public:
    Negate(Calculator& calculator);

    double execute(double value) const;
};

#endif
