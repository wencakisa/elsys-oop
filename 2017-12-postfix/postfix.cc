#include <iostream>

#include "calculator.hh"

#include "negate.hh"
#include "sqrt.hh"
#include "plus.hh"
#include "minus.hh"
#include "multiply.hh"
#include "divide.hh"
#include "dup.hh"
#include "drop.hh"
#include "swap.hh"
#include "rot3.hh"

using namespace std;

int main() {
    Calculator calculator;

    calculator.add_operation(new Negate(calculator));
    calculator.add_operation(new Sqrt(calculator));
    calculator.add_operation(new Plus(calculator));
    calculator.add_operation(new Minus(calculator));
    calculator.add_operation(new Multiply(calculator));
    calculator.add_operation(new Divide(calculator));
    calculator.add_operation(new Dup(calculator));
    calculator.add_operation(new Drop(calculator));
    calculator.add_operation(new Swap(calculator));
    calculator.add_operation(new Rot3(calculator));

    try {
        calculator.run(cin, cout);
    } catch (const CalculatorError& error) {
        cerr << "ERROR: " << error.get_msg() << endl;
    }

    return 0;
}
