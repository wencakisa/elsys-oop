// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: hexagon.hh
// FILE PURPOSE:
//     Class used for drawing a hexagon
//
//     It inherits from the base
//     Figure class from ./figure.hh
//
//     Implementing it's virtual draw() method
// -------------------------------------------

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
