#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

#include "turtle.hh"
#include "svg_turtle.hh"
#include "sierpinski.hh"

#define OUTPUT_FORMAT_INDEX 1
#define CURVE_LEVEL_INDEX 2

#define EPS_FORMAT_STRING "eps"
#define SVG_FORMAT_STRING "svg"

#define CANVAS_DIMENSION 2048
#define LINE_LENGTH 100

using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 2);

    const char* output_format = argv[OUTPUT_FORMAT_INDEX];

    Turtle* t = NULL;

    if (!strcmp(output_format, EPS_FORMAT_STRING)) {
        t = new PSTurtle(CANVAS_DIMENSION, CANVAS_DIMENSION);
    } else if (!strcmp(output_format, SVG_FORMAT_STRING)) {
        t = new SVGTurtle(CANVAS_DIMENSION, CANVAS_DIMENSION);
    }

    t->setup();

    Point center(CANVAS_DIMENSION / 2, CANVAS_DIMENSION / 2);

    int curve_level;
    sscanf(argv[CURVE_LEVEL_INDEX], "%d", &curve_level);

    Sierpinski curve(curve_level, t, LINE_LENGTH, center);
    curve.draw();

    return 0;
}
