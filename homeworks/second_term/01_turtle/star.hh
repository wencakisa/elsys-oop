#ifndef STAR_HH_
#define STAR_HH_

#include "figure.hh"

class Star : public Figure {
    static const int SIDES_ = 6;
public:
    Star(Turtle* turtle, int side_length, const Point& center);

    void draw();
};

#endif
