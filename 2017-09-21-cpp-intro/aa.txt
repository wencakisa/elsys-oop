#include <iostream>

using namespace std;

void fun(int& value) {
    // _________^

    cout << "value = " << value << endl;
    value = 42;
    cout << "new value = " << value << endl;
}

int main() {
    int a = -1;
    fun(a);
    cout << "a = " << a << endl;

    return 0;
}
