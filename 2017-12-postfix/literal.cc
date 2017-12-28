#include "literal.hh"

Literal::Literal(Calculator& calculator, double val)
: Operation(calculator, "#LITERAL#"), val_(val)
{}

void Literal::eval() {
    calculator_.push(val_);
}
