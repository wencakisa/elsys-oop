#include <iostream>

using namespace std;

class Point {
private:
    double x_, y_;
public:
    Point(double x, double y) {
        set_x(x);
        set_y(y);
    }

    void set_x(double x) { x_ = x; }
    double get_x() { return x_; }

    void set_y(double y) { y_ = y; }
    double get_y() { return y_; }

    void print() { cout << "(" << x_ << "; " << y_ << ")" << endl; }
};

int main() {
    Point p1 = Point(1.0, 2.0);
    p1.print();
    p1.set_x(2.5);
    p1.print();

    return 0;
}
