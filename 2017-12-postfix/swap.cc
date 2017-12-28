#include "swap.hh"

Swap::Swap(Calculator& calculator)
: ManipulatingOperation(calculator, "swap")
{}

void Swap::execute() {
    double value1 = calculator_.pop();
    double value2 = calculator_.pop();
    calculator_.push(value1).push(value2);
}
