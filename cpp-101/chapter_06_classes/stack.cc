#include <iostream>
#include <string>

using namespace std;

const int STACK_SIZE = 10;

class Stack {
private:
    int data_[STACK_SIZE];
    int top_;
public:
    Stack() {
        top_ = 0;
    }

    bool is_empty() { return top_ == 0; }
    bool is_full()  { return top_ == STACK_SIZE; }

    void push(int val) {
        if (!is_full()) {
            data_[top_++] = val;
        }
    }

    int pop() {
        if (!is_empty()) {
            return data_[--top_];
        }

        return 0;
    }

};

int main() {
    char msg[STACK_SIZE];
    cout << "Enter a string: ";
    cin >> msg;

    char buff[10];
    Stack st;

    for (char *p = msg; *p != '\0'; p++) {
        st.push(*p);
    }

    char *p = buff;
    while (!st.is_empty()) {
        *p++ = st.pop();
    }
    *p = '\0';

    cout << buff << endl;

    return 0;
}
