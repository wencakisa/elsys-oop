#include <string>
#include <iostream>

#include "manipulating.hh"

using namespace std;

ManipulatingOperation::ManipulatingOperation(Calculator& calculator, const string& name)
: Operation(calculator, name)
{}

void ManipulatingOperation::eval() {
    this->execute();
}
