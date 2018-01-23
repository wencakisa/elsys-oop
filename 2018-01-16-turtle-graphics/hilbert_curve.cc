// #include "turtle.hh"
#include "hilbert_curve.hh"

HilbertCurve::HilbertCurve(int order, int length, Turtle* turtle)
: order_(order), length_(length), turtle_(turtle)
{
    turtle_->setup();
}

HilbertCurve::~HilbertCurve() {
    delete turtle_;
}

void HilbertCurve::left(int order) {
    if (order == 0) {
        turtle_->right(90);
        return;
    }

    order--;

    right(order);
    turtle_->left(90).forward(length_);
    left(order);
    turtle_->right(90).forward(length_);
    left(order);
    turtle_->forward(length_).left(90);
    right(order);
}

void HilbertCurve::right(int order) {
    if (order == 0) {
        turtle_->left(90);
        return;
    }

    order--;

    left(order);
    turtle_->right(90).forward(length_);
    right(order);
    turtle_->left(90).forward(length_);
    right(order);
    turtle_->forward(length_).right(90);
    left(order);
}

void HilbertCurve::draw() {
    turtle_->moveto(Point(0, turtle_->get_width()))
        .right(90)
        .pendown();

    left(order_);
}
