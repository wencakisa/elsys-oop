#ifndef DIVIDE_HH_
#define DIVIDE_HH_

#include "binary.hh"

class Divide : public BinaryOperation {
public:
    Divide(Calculator& calculator);

    double execute(double value1, double value2) const;
};

#endif /* end of include guard: DIVIDE_HH_ */
