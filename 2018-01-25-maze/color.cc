#include <iostream>

#include "color.hh"

using namespace std;


Color::Color(double r, double g, double b)
: r_(r), g_(g), b_(b)
{}

double Color::red() const {
    return r_;
}

double Color::green() const {
    return g_;
}

double Color::blue() const {
    return b_;
}

Color Color::gray(double gray) {
    return Color(gray, gray, gray);
}

ostream& operator<<(ostream& out, const Color& c) {
    out << c.red() << " " << c.green() << " " << c.blue();

    return out;
}
