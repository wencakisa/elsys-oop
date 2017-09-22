#include <iostream>

using namespace std;

void increment(int& count, int step=10);

int main() {
    int a = 1;

    cout << a << endl;
    increment(a, 2);
    cout << a << endl;
    increment(a, 4);
    cout << a << endl;
    increment(a);
    cout << a << endl;

    return 0;
}

void increment(int& count, int step) {
    count += step;
}
