// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: sierpinski_main.cc
// FILE PURPOSE:
//     The main program used for
//     drawing the Sierpinski curve.
//
//     Based on command line parameters,
//     it draws Sierpinski curve from desired
//     order and outputs it to desired format.
// -------------------------------------------

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

#include "turtle.hh"
#include "svg_turtle.hh"
#include "sierpinski.hh"

#define OUTPUT_FORMAT_INDEX 1
#define ORDER_INDEX 2

#define EPS_FORMAT_STRING "eps"
#define SVG_FORMAT_STRING "svg"

#define CANVAS_DIMENSION 2048
#define LINE_LENGTH CANVAS_DIMENSION / 10

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

    int order;
    sscanf(argv[ORDER_INDEX], "%d", &order);

    assert(order > 0 && order < 8);

    Sierpinski curve(t, LINE_LENGTH, center, order);
    curve.draw();

    return 0;
}
