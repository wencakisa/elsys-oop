#include <math.h>

#include "sqrt.hh"

Sqrt::Sqrt(Calculator& calculator) :
UnaryOperation(calculator, "sqrt")
{}

double Sqrt::execute(double value) const {
    return sqrt(value);
}
