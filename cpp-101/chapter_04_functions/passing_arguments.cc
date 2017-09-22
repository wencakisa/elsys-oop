#include <iostream>

using namespace std;

void plus2_value(int x);
void plus2_pointer(int *x);
void plus2_reference(int& x);

int main() {
    int a = 5;

    plus2_value(a);
    cout << a << endl;
    plus2_pointer(&a);
    cout << a << endl;
    plus2_reference(a);
    cout << a << endl;

    return 0;
}

void plus2_value(int x) {
    x += 2;
}

void plus2_pointer(int *x) {
    *x += 2;
}

void plus2_reference(int& x) {
    x += 2;
}
