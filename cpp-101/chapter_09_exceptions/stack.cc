#include <iostream>

using namespace std;

const int STACK_SIZE = 10;

class StackError {
private:
    string message_;
public:
    StackError(string message) {
        message_ = message;
    }

    string get_msg() { return message_; }
};

class Stack {
private:
    int data_[STACK_SIZE];
    int top_;
public:
    Stack() {
        top_ = -1;
    }

    bool is_empty() { return top_ == -1; }
    bool is_full()  { return top_ == STACK_SIZE - 1; }

    void push(int val) {
        if (is_full()) {
            throw StackError("Stack is full.");
        }

        data_[++top_] = val;
    }

    int pop() {
        if (is_empty()) {
            throw StackError("Stack is empty.");
        }

        return data_[top_--];
    }
};

int main() {
    try {
        Stack st;

        for (int i = 0; i < STACK_SIZE; i++) {
            st.push(i);
        }

        for (int i = 0; i < STACK_SIZE; i++) {
            cout << st.pop() << endl;
        }
    } catch (StackError se) {
        cerr << se.get_msg() << endl;
        exit(1);
    } catch (...) {
        cerr << "Error." << endl;
        exit(1);
    }

    return 0;
}
