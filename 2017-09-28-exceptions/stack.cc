#include <iostream>

#include "Stack.hpp"


using namespace std;

int main() {
    try {
        Stack st;

        for (size_t i = 0; i < STACK_SIZE; i++) {
            st.push(i);
        }

        while (!st.is_empty()) {
            cout << st.pop() << endl;
        }
    } catch (StackException ex) {
        ex.print_stack_trace();
        exit(1);
    } catch (...) {
        cerr << "Error!" << endl;
        exit(1);
    }

    return 0;
}
