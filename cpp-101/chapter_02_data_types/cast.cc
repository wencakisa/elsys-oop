#include <iostream>

using namespace std;

int main() {
    int a = 2;
    int b = 3;
    double result = b / a;
    cout << a << " / " << b << " = " << result << endl;

    // Syntax: static_cast<type>(argument)
    result = static_cast<double>(b) / a;
    cout << a << " / " << b << " = " << result << endl;

    return 0;
}
