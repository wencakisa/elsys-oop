#ifndef BINARY_HH_
#define BINARY_HH_

#include "operation.hh"

class BinaryOperation : public Operation {
public:
    BinaryOperation(Calculator& calculator, const std::string& name);

    void eval();

protected:
    virtual double execute(double value1, double value2) const = 0;
};

#endif
