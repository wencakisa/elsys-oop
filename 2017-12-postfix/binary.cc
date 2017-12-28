#include <string>

#include "binary.hh"

using namespace std;

BinaryOperation::BinaryOperation(Calculator& calculator, const string& name)
: Operation(calculator, name)
{}

void BinaryOperation::eval() {
    double value1 = calculator_.pop();
    double value2 = calculator_.pop();
    calculator_.push(this->execute(value1, value2));
}
