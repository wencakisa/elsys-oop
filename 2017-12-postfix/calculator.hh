#ifndef CALCULATOR_HH_
#define CALCULATOR_HH_

#include <string>
#include <vector>

class Operation;

class CalculatorError {
    const std::string message_;
public:
    CalculatorError(const std::string& message);

    const std::string& get_msg() const {
        return message_;
    }
};

class Calculator {
    std::vector<Operation*> operations_;
    std::vector<double> stack_;
public:
    Calculator();

    void add_operation(Operation* op);
    Operation* get_operation(const std::string& name);

    Calculator& push(double val);
    int size() const;
    bool empty() const;
    double pop();

    void add_macro(const std::string& word, std::istream& in, std::ostream& out);
    void run(std::istream& in, std::ostream& out);
};

#endif
