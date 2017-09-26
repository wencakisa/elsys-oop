#include <iostream>

using namespace std;

#define STACK_SIZE 10

class Stack {
    int data_[STACK_SIZE];
    int top_;
public:
    Stack() : top_(0) {}

    bool full()  { return top_ == STACK_SIZE; };
    bool empty() { return top_ == 0; }

    void push(int val) {
        if (full()) {
            cerr << "Stack is full!" << endl;
            return;
        }

        data_[top_++] = val;
    }

    int pop() {
        if (empty()) {
            cerr << "Stack is empty!" << endl;
            return -1;
        }

        return data_[--top_];
    }
};

int main() {
    Stack st;

    for (size_t i = 0; i < STACK_SIZE; ++i) {
        st.push(i);
    }

    while(!st.empty()) {
        cout << "Pop: " << st.pop() << endl;
    }

    return 0;
}
