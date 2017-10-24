#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Point {
    double x_, y_;
    double cx_, cy_;
public:
    static constexpr double DEFAULT_CX_ = 0, DEFAULT_CY_ = 0;

    Point() :
        x_(DEFAULT_CX_), y_(DEFAULT_CY_), cx_(DEFAULT_CX_), cy_(DEFAULT_CY_) {}

    Point(double x, double y) :
        x_(x), y_(y), cx_(DEFAULT_CX_), cy_(DEFAULT_CY_) {}

    Point(double x, double y, double cx, double cy) :
        x_(x), y_(y), cx_(cx), cy_(cy) {}

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

    Point transform_in(double new_cx, double new_cy) const {
        return Point(x_ + cx_ - new_cx, y_ + cy_ - new_cy, new_cx, new_cy);
    }

    Point transform_in_default() const {
        return transform_in(DEFAULT_CX_, DEFAULT_CY_);
    }

    Point& operator+=(const Point& other) {
        Point other_transformed = other.transform_in(cx_, cy_);

        x_ += other_transformed.x_;
        y_ += other_transformed.y_;

        return *this;
    }

    void draw() const {
        // TODO: Implement
    }
};

Point operator+(const Point& p1, const Point& p2) {
    Point result = p1;
    result += p2;

    return result;
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "Point (" << p.get_x() << "; " << p.get_y() << ") in ("
                     << p.get_cx() << "; " << p.get_cy() << ")";

    return out;
}

int main() {
    Point p1, p2(3, 5), p3(1, 2, 3, 4);

    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);

    for (auto it = points.begin(); it != points.end(); ++it) {
        Point p = *it;
        p.draw();
    }

    return 0;
}
