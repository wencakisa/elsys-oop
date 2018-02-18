#ifndef FIGURE_HH_
#define FIGURE_HH_

#include "turtle.hh"

class Figure {
protected:
    Turtle* turtle_;
    int side_length_;
    const Point& center_;
public:
    Figure(Turtle* turtle, int side_length, const Point& center);

    virtual void draw() = 0;
};

#endif
