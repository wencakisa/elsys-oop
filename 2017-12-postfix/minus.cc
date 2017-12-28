#include "minus.hh"

Minus::Minus(Calculator& calculator)
: BinaryOperation(calculator, "-")
{}

double Minus::execute(double value1, double value2) const {
    return value2 - value1;
}
