#include <iostream>

using namespace std;

class Point {
    double x_, y_;
    const double cx_, cy_;
public:
    static constexpr double DEFAULT_CX_ = 0, DEFAULT_CY_ = 0;

    Point(double x, double y) :
        x_(x), y_(y), cx_(DEFAULT_CX_), cy_(DEFAULT_CY_) {}

    Point(double x, double y, double cx, double cy) :
        x_(x), y_(y), cx_(cx), cy_(cy) {}

    static Point get_default_beginning() {
        return Point(DEFAULT_CX_, DEFAULT_CY_);
    }

    double get_x() const {
        return x_;
    }

    Point& set_x(double x) {
        x_ = x;
        return *this;
    }

    double get_y() const {
        return y_;
    }

    Point& set_y(double y) {
        y_ = y;
        return *this;
    }

    double get_cx() const {
        return cx_;
    }

    double get_cy() const {
        return cy_;
    }

    Point transform_in(double new_cx, double new_cy) {
        return Point(x_ + cx_ - new_cx, y_ + cy_ - new_cy, new_cx, new_cy);
    }

    Point transform_in_default() {
        return transform_in(DEFAULT_CX_, DEFAULT_CY_);
    }

    void print() const {
        cout << "(" << x_ << "; " << y_ << ") in ("
             << cx_ << "; " << cy_ << ")" << endl;
    }
};

int main() {
    Point p1(3, 2);
    p1.set_x(2).set_y(1).print();

    Point p2 = p1.transform_in(5, 2);
    p2.print();

    Point p3 = p2.transform_in_default();
    p3.print();

    return 0;
}
