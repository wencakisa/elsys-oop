// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: svg_turtle.hh
// FILE PURPOSE:
//     Class used for drawing Turtle graphics
//     into an SVG format
//
//     It inherits from the base
//     Turtle class from ./turtle.hh
// -------------------------------------------

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
    // -------------------------------------------
    // FUNCTION: <opening|closing>_tag
    //     Represents a given string as an SVG tag
    //     (e.g. "<tag>" or "</tag>")
    // PARAMETERS:
    //     const std::string name - The tag name
    // -------------------------------------------
    std::string opening_tag(const std::string name);
    std::string closing_tag(const std::string name);
    // -------------------------------------------
    // FUNCTION: as_attribute
    //     Represents a given key and value as an
    //     SVG attribute (e.g. "key=value")
    // PARAMETERS:
    //     const std::string key - The key
    //     const double value    - The value
    // -------------------------------------------
    std::string as_attribute(const std::string key, const double value);
};

#endif
