#include <iostream>
#include <sstream>

#include "svg_turtle.hh"

using namespace std;


SVGTurtle::SVGTurtle(double width, double height, ostream& out)
: Turtle(width, height), out_(out)
{}

SVGTurtle::~SVGTurtle() {
    out_ << closing_tag("svg") << endl;
    out_ << closing_tag("body") << endl;
    out_ << closing_tag("html") << endl;
}

Turtle& SVGTurtle::setup() {
    out_ << "<!DOCTYPE HTML>" << endl;
    out_ << opening_tag("html") << endl;
    out_ << opening_tag("body") << endl;
    out_ << opening_tag("h1") << "SVG Turtle Graphics" << closing_tag("h1") << endl;

    out_ << "<svg";
    out_ << as_attribute("width", get_width());
    out_ << as_attribute("height", get_height());
    out_ << ">" << endl;

    Turtle::setup();

    return *this;
}

Turtle& SVGTurtle::moveto(const Point& p) {
    if (is_pendown()) {
        out_ << "<line";

        Point pos = this->get_pos();
        out_ << as_attribute("x1", pos.get_x());
        out_ << as_attribute("y1", pos.get_y());

        Turtle::moveto(p);

        pos = get_pos();
        out_ << as_attribute("x2", pos.get_x());
        out_ << as_attribute("y2", pos.get_y());

        Color c = this->get_color();
        out_ << " style=\"";
        out_ << "stroke:rgb(" << c.red() * 255 << ","
                << c.green() * 255 << ","
                << c.blue() * 255 << ");";
        out_ << "stroke-width:" << this->get_pensize();

        out_ << "\"" << " />" << endl;
    } else {
        Turtle::moveto(p);
    }

    return *this;
}

string SVGTurtle::opening_tag(const string name) {
    return "<" + name + ">";
}

string SVGTurtle::closing_tag(const string name) {
    return "</" + name + ">";
}

string SVGTurtle::as_attribute(const string key, const double value) {
    ostringstream ostr;
    ostr << value;

    return " " + key + "=\"" + ostr.str() + "\"";
}
