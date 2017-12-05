#ifndef CIRCLE_HH__
#define CIRCLE_HH__

#include "shape.hh"
#include "point.hh"

class Circle : public Shape {
    Point center_;
    double radius_;
public:
    Circle(const Point& center, double radius);
    
    double get_radius() const;
    Point get_center() const;
    void set_radius(double radius);
    void set_center(Point& point);
    void draw() const;
};

#endif
