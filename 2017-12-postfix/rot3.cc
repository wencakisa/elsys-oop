#include "rot3.hh"

Rot3::Rot3(Calculator& calculator)
: ManipulatingOperation(calculator, "rot3")
{}

void Rot3::execute() {
    double value1 = calculator_.pop();
    double value2 = calculator_.pop();
    double value3 = calculator_.pop();
    calculator_.push(value1).push(value3).push(value2);
}
