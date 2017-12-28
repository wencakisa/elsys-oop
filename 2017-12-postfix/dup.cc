#include "dup.hh"

Dup::Dup(Calculator& calculator)
: ManipulatingOperation(calculator, "dup")
{}

void Dup::execute() {
    double last = calculator_.pop();
    calculator_.push(last).push(last);
}
