#include <iostream>

using namespace std;

#define MAX_LEN 20

#define OPENING_BRACKET '('
#define CLOSING_BRACKET ')'

class Stack {
    int elements_[MAX_LEN];
    int top_;
public:
    Stack() : top_(0) {}

    int get_top() { return top_; }

    bool empty() { return top_ == 0; }
    bool full()  { return top_ == MAX_LEN; }

    void push(int symbol) {
        if (full()) {
            cerr << "Stack is full." << endl;
            return;
        }

        elements_[top_++] = symbol;
    }

    int pop() {
        if (empty()) {
            cerr << "Stack is empty." << endl;
            return -1;
        }

        return elements_[--top_];
    }
};

bool is_opening(char symbol) { return symbol == OPENING_BRACKET; }
bool is_closing(char symbol) { return symbol == CLOSING_BRACKET; }

int main() {
    Stack ob_stack, cb_stack;
    string brackets;

    cout << "Enter brackets sequence: ";
    cin >> brackets;

    for (size_t i = 0; i < brackets.length(); ++i) {
        char symbol = brackets[i];

        if (is_opening(symbol)) {
            ob_stack.push(0);
        } else if (is_closing(symbol)) {
            cb_stack.push(0);
        }
    }

    cout << "Brackets are " << ((ob_stack.get_top() == cb_stack.get_top()) ? "" : "not ") << "balanced." << endl;

    return 0;
}
