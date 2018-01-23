#include <iostream>

#include "ps_turtle.hh"
#include "hilbert_curve.hh"

using namespace std;

int main() {
    HilbertCurve curve(1, 20, new PSTurtle(500, 500));
    curve.draw();

    return 0;
}
