#include <iostream>
#include "stack.hh"

using namespace std;

int main() {
    Stack<int> i_stack;
    Stack<double> d_stack;

    for (size_t i = 0; i < STACK_SIZE; i++) {
        i_stack.push(i * 10);
        d_stack.push(i * 3.14);
    }

    while (!i_stack.is_empty()) {
        cout << i_stack.pop() << "\t" << d_stack.pop() << endl;
    }

    return 0;
}
