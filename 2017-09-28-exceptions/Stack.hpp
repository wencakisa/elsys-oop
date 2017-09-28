#ifndef POINT_HPP__
#define POINT_HPP__

#include "BaseException.hpp"


#define STACK_SIZE 20

class StackException : public BaseException {
public:
    StackException(string msg) : BaseException(msg) {}
};

class Stack {
    int data_[STACK_SIZE];
    int top_;
public:
    Stack() : top_(0) {}

    bool is_empty() const {
        return top_ == 0;
    }

    bool is_full() const {
        return top_ == STACK_SIZE;
    }

    void push(int val) {
        if (is_full()) {
            throw StackException("Stack is full.");
        }

        data_[top_++] = val;
    }

    int pop() {
        if (is_empty()) {
            throw StackException("Stack is empty.");
        }

        return data_[--top_];
    }
};

#endif
