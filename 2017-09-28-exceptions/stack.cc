#include <iostream>

using namespace std;

#define STACK_SIZE 20

class BaseException {
    string message_;
public:
    BaseException(string msg) : message_(msg) {}

    string get_msg() {
        return message_;
    }

    void print_stacktrace() {
        cerr << "Error: " << get_msg() << endl;
    }
};

class StackException : public BaseException {
public:
    StackException(string msg) : BaseException(msg) {}
};

class Stack {
    int data_[STACK_SIZE];
    int top_;
public:
    Stack() : top_(0) {}

    bool is_empty() {
        return top_ == 0;
    }

    bool is_full() {
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

int main() {
    try {
        Stack st;

        for (size_t i = 0; i < STACK_SIZE + 1; i++) {
            st.push(i);
        }

        while (!st.is_empty()) {
            cout << st.pop() << endl;
        }
    } catch (StackException ex) {
        ex.print_stacktrace();
        exit(1);
    } catch (...) {
        cerr << "Error!" << endl;
        exit(1);
    }

    return 0;
}
