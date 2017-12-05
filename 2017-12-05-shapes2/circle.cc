#include <iostream>

#include "point.hh"
#include "circle.hh"

Circle::Circle(const Point& center, double radius)
: center_(center), radius_(radius)
{}

double Circle::get_radius() const {
    return radius_;
}

Point Circle::get_center() const {
    return center_;
}

void Circle::set_radius(double radius) {
    radius_ = radius;
}

void Circle::set_center(Point& point) {
    center_ = point;
}

void Circle::draw() const {
    std::cout << "Circle(" << center_ << "; " << radius_ << ")" << std::endl;
}
