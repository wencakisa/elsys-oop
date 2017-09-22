#include <iostream>

using namespace std;

void plus2(int& x) {
    x += 2;
}

int main() {
    int i = 1;
    cout << "i = " << i << endl;

    int& r = i; // <<<
    r = 2;
    cout << "i = " << i << endl;

    // Invalid definitions:
    // int &r;
    // int &r = 10;

    int i2 = 42;
    r = i2; // Doesn't reassign reference. Just assigns i's value to be i2's one.
    cout << "i = " << i << endl;

    plus2(i);
    cout << "i = " << i << endl;

    return 0;
}
