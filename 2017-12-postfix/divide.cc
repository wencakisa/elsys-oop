#include "divide.hh"

Divide::Divide(Calculator& calculator)
: BinaryOperation(calculator, "/")
{}

double Divide::execute(double value1, double value2) const {
    return value2 / value1;
}
