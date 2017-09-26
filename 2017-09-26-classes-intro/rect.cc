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
};

class Rectangle {
    Point bl_;
    Point ur_;
public:
    Rectangle(Point bl, Point ur) :
        bl_(bl.get_x(), bl.get_y()),
        ur_(ur.get_x(), ur.get_y()) {}

    Rectangle(double x, double y, double w, double h) :
        bl_(x, y),
        ur_(x + w, y + h) {}

    Point get_bl() { return bl_; }
    Point get_ur() { return ur_; }
};

int main() {
    Point bottom_left(3.2, 2.0);
    Point upper_right(5.0, 3.0);

    Rectangle r(bottom_left, upper_right);

    return 0;
}
