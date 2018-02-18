#ifndef SVG_TURTLE_HH_
#define SVG_TURTLE_HH_

#include <iostream>

#include "turtle.hh"

class SVGTurtle : public Turtle {
    std::ostream& out_;
public:
    SVGTurtle(double width, double height, std::ostream& out=std::cout);
    virtual ~SVGTurtle();

    virtual Turtle& setup();

    virtual Turtle& moveto(const Point& p);

private:
    std::string opening_tag(const std::string name);
    std::string closing_tag(const std::string name);

    std::string as_attribute(const std::string key, const double value);
};

#endif
