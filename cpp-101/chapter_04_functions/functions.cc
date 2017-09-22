#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

double area(double r);
double distance(double x1, double y1, double x2, double y2);

int main() {
    double r = 5.2;
    double a = area(r);
    cout << a << endl;

    double x1 = 2.0;
    double y1 = 3.5;
    double x2 = 4.2;
    double y2 = 0.7;
    double d = distance(x1, y1, x2, y2);
    cout << d << endl;

    return 0;
}

double area(double r) {
    return PI * r * r;
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}
