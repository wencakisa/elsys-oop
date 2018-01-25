#include <iostream>

#include "color.hh"
#include "ps_turtle.hh"

using namespace std;

PSTurtle::PSTurtle(double width, double height, ostream& out)
: Turtle(width, height), out_(out)
{}

PSTurtle::~PSTurtle() {
    out_ << "stroke" << endl;
    out_ << "%%EOF" << endl;
}

Turtle& PSTurtle::setup() {
    out_ << "%!PS-Adobe-3.0 EPSF-3.0" << endl;
    out_ << "%%Creator: sisonio" << endl;
    out_ << "%%DocumentData: Clean7Bit" << endl;
    out_ << "%%BoundingBox: 0 0 " << get_width() << " " << get_height() << endl;
    out_ << "%%Pages: 1" << endl;
    out_ << "%%Page: 1 1" << endl;

    out_ << "newpath" << endl;
    out_ << get_pos() << " moveto" << endl;

    return *this;
}

Turtle& PSTurtle::moveto(const Point& next_pos) {
    out_ << next_pos << " ";

    out_ << (is_pendown() ? "lineto" : "moveto") << endl;

    Turtle::moveto(next_pos);

    return *this;
}

Turtle& PSTurtle::set_pos(const Point& p) {
    Turtle::set_pos(p);
    out_ << get_pos() << " moveto" << endl;

    return *this;
}

Turtle& PSTurtle::pensize(double width) {
    Turtle::pensize(width);

    out_ << get_pensize() << " setlinewidth" << endl;

    return *this;
}

Turtle& PSTurtle::pencolor(const Color& c) {
    Turtle::pencolor(c);

    out_ << get_color() << " setrgbcolor" << endl;

    return *this;
}
