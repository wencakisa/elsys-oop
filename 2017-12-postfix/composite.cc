#include <string>

#include "composite.hh"

using namespace std;

CompositeOperation::CompositeOperation(Calculator& calculator, const string& name)
: Operation(calculator, name)
{}

void CompositeOperation::add_child(Operation *op) {
    children_.push_back(op);
}

void CompositeOperation::eval() {
    for (Operation* child : children_) {
        child->eval();
    }
}
