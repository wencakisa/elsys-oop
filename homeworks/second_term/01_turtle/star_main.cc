// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: star_main.cc
// FILE PURPOSE:
//     The main program used for
//     drawing the Star.
//
//     Based on command line parameters,
//     it draws a star and outputs it
//     to a desired format.
// -------------------------------------------

#include <iostream>
#include <cstring>
#include <cassert>

#include "turtle.hh"
#include "svg_turtle.hh"
#include "axis.hh"
#include "star.hh"

#define OUTPUT_FORMAT_INDEX 1
#define EPS_FORMAT_STRING "eps"
#define SVG_FORMAT_STRING "svg"

#define CANVAS_DIMENSION 1000
#define LINE_LENGTH 200

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

    Star star(t, LINE_LENGTH, center);
    star.draw();

    delete t;

    return 0;
}
