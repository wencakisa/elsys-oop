#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

#define STACK_SIZE 10

class StackError {
    string message_;
public:
    StackError(string msg) : message_(msg) {}

    string get_msg() {
        return message_;
    }

    void print_stack_trace() {
        cout << "StackError: " << get_msg() << endl;
    }
};

template <typename T> class Stack {
    T data_[STACK_SIZE];
    int top_;
public:
    Stack() : top_(0) {}

    bool is_empty() const {
        return top_ == 0;
    }

    bool is_full() const {
        return top_ == STACK_SIZE;
    }

    void push(T val) {
        if (is_full()) {
            throw StackError("Stack is full!");
        }

        data_[top_++] = val;
    }

    T pop() {
        if (is_empty()) {
            throw StackError("Stack is empty!");
        }

        return data_[--top_];
    }
};

#endif
