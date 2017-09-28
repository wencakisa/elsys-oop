#ifndef BASE_EXCEPTION_HPP__
#define BASE_EXCEPTION_HPP__

#include <iostream>


using namespace std;

class BaseException {
    string message_;
public:
    BaseException(string msg) : message_(msg) {}

    string get_msg() const {
        return message_;
    }

    void print_stack_trace() const {
        cerr << "Error: " << get_msg() << endl;
    }
};

#endif
