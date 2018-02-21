// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: star.hh
// FILE PURPOSE:
//     Class used for drawing a 6-sided star
//
//     It inherits from the base
//     Figure class from ./figure.hh
//
//     Implementing it's virtual draw() method
// -------------------------------------------

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
