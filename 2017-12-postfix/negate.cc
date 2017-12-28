#include "negate.hh"

Negate::Negate(Calculator& calculator)
: UnaryOperation(calculator, "neg")
{}

double Negate::execute(double value) const {
    return -value;
}
