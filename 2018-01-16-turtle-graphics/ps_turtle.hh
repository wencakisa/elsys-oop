#ifndef PS_TURTLE_HH_
#define PS_TURTLE_HH_

#include <iostream>

#include "color.hh"
#include "turtle.hh"

class PSTurtle : public Turtle {
    std::ostream& out_;
public:
    PSTurtle(double width, double height, std::ostream& out = std::cout);
    ~PSTurtle();

    Turtle& setup();

    Turtle& moveto(const Point& next_pos);

    Turtle& pensize(double size = 1.0);
    Turtle& pencolor(const Color& c);

    Turtle& dot(double size);
};

#endif
