#include "plus.hh"

Plus::Plus(Calculator& calculator)
: BinaryOperation(calculator, "+")
{}

double Plus::execute(double value1, double value2) const {
    return value1 + value2;
}
