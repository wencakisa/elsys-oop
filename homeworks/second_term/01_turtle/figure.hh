// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: figure.hh
// FILE PURPOSE:
//     Base class used for drawing Figures
//
//     Contains only one pure abstract method
//     void draw()
//     which should be overriden in children
// -------------------------------------------

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
