// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: sierpinski.hh
// FILE PURPOSE:
//     Definition of the Sierpinski curve
//     implemented in ./sierpinski.cc
//
//     This solution of the Sierpinski curve
//     is based on the one in the book
//     "Algorithms and data structures" from N.Wirth
//     (http://www.ethoberon.ethz.ch/WirthPubl/AD.pdf)
//
//     and also on the Hilbert curve implementation in
//     https://github.com/elsys/oop2017-2018/tree/master/examples/hilbert
// -------------------------------------------

#ifndef SIERPINSKI_HH_
#define SIERPINSKI_HH_

#include "figure.hh"
#include "turtle.hh"

class Sierpinski : public Figure {
    int order_;
    double step_;
public:
    Sierpinski(Turtle* turtle, int side_length, const Point& center, int order);
    ~Sierpinski();

    // -------------------------------------------
    // FUNCTION: draw
    //     By calling the private draw_* functions
    //     draws a Sierpinski curve of the order,
    //     passed in the class constructor
    // PARAMETERS: No parameters
    // -------------------------------------------
    void draw();
private:
    // -------------------------------------------
    // FUNCTION: calculate_step
    //     Calculates the Turtle step for drawing
    //     based on the current curve order
    // PARAMETERS:
    //     int order - The current curve order
    // -------------------------------------------
    double calculate_step(int order);

    // -------------------------------------------
    // FUNCTION: draw_*
    //     The next four functions are recursively
    //     calling each other and drawing the four
    //     sides of a Sierpinski curve (A, B, C, D)
    // PARAMETERS:
    //     int order - The current curve order
    // -------------------------------------------
    void draw_a(int order);
    void draw_b(int order);
    void draw_c(int order);
    void draw_d(int order);
};

#endif
