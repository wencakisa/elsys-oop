#ifndef AXIS_HH_
#define AXIS_HH_

#include "figure.hh"

class Axis : public Figure {
public:
    Axis(Turtle* t, int side_length, const Point& center);

    void draw();
};

#endif
