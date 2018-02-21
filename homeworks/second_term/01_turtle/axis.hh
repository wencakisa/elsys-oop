// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: axis.hh
// FILE PURPOSE:
//     Class used for drawing axis
//
//     It inherits from the base
//     Figure class from ./figure.hh
//
//     Implementing it's virtual draw() method
// -------------------------------------------

#ifndef AXIS_HH_
#define AXIS_HH_

#include "figure.hh"

class Axis : public Figure {
public:
    Axis(Turtle* t, int side_length, const Point& center);

    void draw();
};

#endif
