#ifndef HEXAGON_HH_
#define HEXAGON_HH_

#include "figure.hh"

class Hexagon : public Figure {
    static const int SIDES_ = 6;
public:
    Hexagon(Turtle* turtle, int side_length, const Point& center);

    void draw();
};

#endif
