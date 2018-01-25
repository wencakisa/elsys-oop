#include <iostream>
#include <cmath>

#include "point.hh"

using namespace std;


Point::Point(double x, double y) : x_(x), y_(y) {}

Point Point::polar(double angle, double distance) {
    double radians = (angle * M_PI) / 180.0;

    double x = distance * cos(radians);
    double y = distance * sin(radians);

    return Point(x, y);
}

Point Point::cartesian(double x, double y) {
    return Point(x, y);
}

double Point::get_x() const {
    return x_;
}

double Point::get_y() const {
    return y_;
}

Point& Point::operator+=(const Point& other) {
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

Point& Point::operator-=(const Point& other) {
    x_ -= other.x_;
    y_ -= other.y_;

    return *this;
}

Point operator+(const Point& p1, const Point& p2) {
    Point result(p1);
    result += p2;

    return result;
}

Point operator-(const Point& p1, const Point& p2) {
    Point result(p1);
    result -= p2;

    return result;
}

ostream& operator<<(ostream& out, const Point& p) {
    out << p.get_x() << " " << p.get_y();

    return out;
}
