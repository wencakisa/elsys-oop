#include "drop.hh"

Drop::Drop(Calculator& calculator)
: ManipulatingOperation(calculator, "drop")
{}

void Drop::execute() {
    calculator_.pop();
}
