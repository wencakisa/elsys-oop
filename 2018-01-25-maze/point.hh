#ifndef POINT_HH_
#define POINT_HH_

#include <iostream>

class Point {
    double x_, y_;
public:
    Point(double x = 0.0, double y = 0.0);

    static Point polar(double angle, double distance);
    static Point cartesian(double x, double y);

    double get_x() const;
    double get_y() const;

    Point& operator+=(const Point& other);
    Point& operator-=(const Point& other);
};

Point operator+(const Point& p1, const Point& p2);
Point operator-(const Point& p1, const Point& p2);

std::ostream& operator<<(std::ostream& out, const Point& p);

#endif
