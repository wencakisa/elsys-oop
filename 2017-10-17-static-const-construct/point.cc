#include <iostream>

using namespace std;

class Point {
    double x_, y_;
    const double cx_, cy_;
public:
    static constexpr double DEFAULT_CX_ = 0, DEFAULT_CY_ = 0;

    Point(double x, double y) : x_(x), y_(y), cx_(DEFAULT_CX_), cy_(DEFAULT_CY_) {}
    
    Point(double x, double y, double cx, double cy) : x_(x), y_(y), cx_(cx), cy_(cy) {}

    static Point get_default_beginning() {
        return Point(DEFAULT_CX_, DEFAULT_CY_);
    }

    double get_x() {
        return x_;
    }

    void set_x(double x) {
        x_ = x;
    }

    double get_y() {
        return y_;
    }

    void set_y(double y) {
        y_ = y;
    }

    Point transform_in(double new_cx, double new_cy) {
        return Point(x_ + cx_ - new_cx, y_ + cy_ - new_cy, new_cx, new_cy);
    }

    Point transform_in_default() {
        return transform_in(DEFAULT_CX_, DEFAULT_CY_);
    }

    void print() {
        cout << "(" << x_ << "; " << y_ << ") in (" << cx_ << "; " << cy_ << ")" << endl;
    }
};

int main() {
    cout << "Default coord system:";
    Point::get_default_beginning().print();

    Point p1(0, 0, 6, 3);
    Point p2(1, 1, 5, 5);
    p1.print();
    cout << "In default: ";
    p1.transform_in_default().print();
    p2.print();
    cout << "In (1; 1)";
    p2.transform_in(1, 1).print();

    return 0;
}
