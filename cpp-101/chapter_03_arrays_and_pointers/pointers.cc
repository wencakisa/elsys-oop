#include <iostream>

using namespace std;

int main() {
    int a = 42;
    cout << "a = " << a << endl;

    int *p = &a;
    cout << "&a = " << p << endl;

    int b = *p;
    cout << "b = " << b << endl;

    *p -= 12;
    cout << "a = " << a << endl;

    return 0;
}
