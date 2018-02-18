#include <iostream>
#include <cstring>
#include <cassert>

#include "turtle.hh"
#include "svg_turtle.hh"
#include "axis.hh"
#include "hexagon.hh"

#define OUTPUT_FORMAT_INDEX 1
#define EPS_FORMAT_STRING "eps"
#define SVG_FORMAT_STRING "svg"

#define CANVAS_DIMENSION 1000
#define LINE_LENGTH 400

using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 1);

    const char* output_format = argv[OUTPUT_FORMAT_INDEX];

    Turtle* t = NULL;

    if (!strcmp(output_format, EPS_FORMAT_STRING)) {
        t = new PSTurtle(CANVAS_DIMENSION, CANVAS_DIMENSION);
    } else if (!strcmp(output_format, SVG_FORMAT_STRING)) {
        t = new SVGTurtle(CANVAS_DIMENSION, CANVAS_DIMENSION);
    }

    t->setup();

    Point center(CANVAS_DIMENSION / 2, CANVAS_DIMENSION / 2);

    Axis axis(t, CANVAS_DIMENSION, center);
    axis.draw();

    Hexagon hexagon(t, LINE_LENGTH, center);
    hexagon.draw();

    delete t;

    return 0;
}
