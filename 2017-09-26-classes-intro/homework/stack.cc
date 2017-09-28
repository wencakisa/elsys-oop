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
            return -1;
        }

        return elements_[--top_];
    }
};

bool is_opening(char symbol) { return symbol == OPENING_BRACKET; }
bool is_closing(char symbol) { return symbol == CLOSING_BRACKET; }

int main() {
    Stack st;
    string brackets;

    cout << "Enter brackets sequence: ";
    cin >> brackets;

    for (size_t i = 0; i < brackets.length(); ++i) {
        char symbol = brackets[i];

        if (is_opening(symbol)) {
            st.push(0);
        } else if (is_closing(symbol)) {
            if (st.pop() == -1) {
                cout << "Brackets are not balanced." << endl;
                return 0;
            }
        }
    }

    cout << "Brackets are " << (st.empty() ? "" : "not ") << "balanced." << endl;
    return 0;
}
