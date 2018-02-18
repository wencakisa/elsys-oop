#ifndef SIERPINSKI_HH_
#define SIERPINSKI_HH_

#include "figure.hh"
#include "turtle.hh"

class Sierpinski : public Figure {
    int level_;
public:
    Sierpinski(int level, Turtle* turtle, int side_length, const Point& center);
    ~Sierpinski();

    void draw();
private:
    void left(int level);
    void right(int level);
};

#endif
