#include <iostream>

using namespace std;

class Point {
    double x_;
    double y_;
public:
    Point(double x=0.0, double y=0.0) : x_(x), y_(y) {}

    double get_x() { return x_; }
    double get_y() { return y_; }

    void set_x(double x) { x_ = x; }
    void set_y(double y) { y_ = y; }

    void print() {
        cout << "(" << get_x() << "; " << get_y() << ")" << endl;
    }
};

int main() {
    Point p;
    p.print();

    p = Point(3.2, 2.0);
    p.print();

    return 0;
}
