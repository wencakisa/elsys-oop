#include <iostream>

using namespace std;

class Point {
    double x_, y_;

public:
    void set_x(double x) {
        x_ = x;
    }
};

int main() {
    Point p1, p2;
    p1.set_x(2.5);
    // p2.x = 3.2;

    return 0;
}
