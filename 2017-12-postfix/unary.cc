#include <string>

#include "unary.hh"

using namespace std;

UnaryOperation::UnaryOperation(Calculator& calculator, const string& name)
: Operation(calculator, name)
{}

void UnaryOperation::eval() {
    double value = calculator_.pop();
    calculator_.push(this->execute(value));
}
