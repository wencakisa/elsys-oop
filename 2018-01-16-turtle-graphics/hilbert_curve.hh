#ifndef HILBERT_CURVE_HH_
#define HILBERT_CURVE_HH_

#include "turtle.hh"

class HilbertCurve {
    int order_;
    Turtle* turtle_;
    int length_;
public:
    HilbertCurve(int order, int length, Turtle* turtle);
    ~HilbertCurve();

    void draw();
private:
    void left(int order);

    void right(int order);
};

#endif
