// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: sierpinski.cc
// FILE PURPOSE:
//     Definition of the Sierpinski curve
//     implemented in ./sierpinski.cc
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

    void draw();
private:
    double calculate_step(int order);

    void draw_a(int order);
    void draw_b(int order);
    void draw_c(int order);
    void draw_d(int order);
};

#endif
