#include "multiply.hh"

Multiply::Multiply(Calculator& calculator)
: BinaryOperation(calculator, "*")
{}

double Multiply::execute(double value1, double value2) const {
    return value1 * value2;
}
