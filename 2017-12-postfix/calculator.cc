#include <iostream>
#include <string>
#include <sstream>

#include "operation.hh"
#include "calculator.hh"
#include "composite.hh"
#include "literal.hh"

using namespace std;

CalculatorError::CalculatorError(const string& message)
: message_(message)
{}

Calculator::Calculator() {}

void Calculator::add_operation(Operation *op) {
    if (get_operation(op->get_name()) != nullptr) {
        cout << "Operation <" << op->get_name() << "> already exists" << endl;
    } else {
        operations_.push_back(op);
    }
}

Operation* Calculator::get_operation(const string& name) {
    for (Operation* op : operations_) {
        if (op->get_name() == name) {
            return op;
        }
    }

    return nullptr;
}

bool Calculator::empty() const {
    return stack_.empty();
}

int Calculator::size() const {
    return stack_.size();
}

Calculator& Calculator::push(double val) {
    stack_.push_back(val);
    return *this;
}

double Calculator::pop() {
    if (empty()) {
        throw CalculatorError("Calculator is empty.");
    }

    double val = stack_.back();
    stack_.pop_back();
    return val;
}

void Calculator::add_macro(const string& word, istream& in, ostream& out) {
    string name = word.substr(1);
    CompositeOperation* macro = new CompositeOperation(*this, name);

    string token;

    while (true) {
        out << "--> ";
        in >> token;

        if (!in.good()) {
            throw CalculatorError("Bad syntax in macro definition");
        }

        if (token == "def") {
            break;
        }

        Operation* op = this->get_operation(token);

        if (op != nullptr) {
            macro->add_child(op);
        } else {
            istringstream iss(token);

            double val;
            iss >> val;

            if (!iss.fail()) {
                macro->add_child(new Literal(*this, val));
            } else {
                throw CalculatorError("Unknown literal in macro definition");
            }
        }
    }

    add_operation(macro);
    out << "Macro <" << macro->get_name() << "> added." << endl;
}

void Calculator::run(istream& in, ostream& out) {
    cout << "Run!" << endl;

    string token;

    while (true) {
        out << "(" << this->size() << ") " << "> ";
        in >> token;

        if (!in.good() || token == "quit") {
            break;
        }

        // Macro definition
        if (token[0] == '\\') {
            this->add_macro(token, in, out);
        } else {
            Operation* op = this->get_operation(token);

            if (op != nullptr) {
                op->eval();
                cout << this->stack_.back() << endl;
            } else {
                istringstream iss(token);

                double val;
                iss >> val;

                if (!iss.fail()) {
                    this->push(val);
                } else {
                    out << "ERROR: Unknown token <" << token << ">" << endl;
                }
            }
        }
    }
}
