#include <iostream>

using namespace std;

int add(int a, int b);
double add(double a, double b);

int main() {
    cout << add(3, 5) << endl;
    cout << add(3.5, 4.5) << endl;

    return 0;
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
