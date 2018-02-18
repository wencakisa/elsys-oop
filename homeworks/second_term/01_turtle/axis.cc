#include "axis.hh"

Axis::Axis(Turtle* turtle, int side_length, const Point& center)
: Figure(turtle, side_length, center)
{}

void Axis::draw() {
    turtle_->moveto(center_)
        .penup()
        .right(90)
        .forward(side_length_ / 2)
        .pendown()
        .right(180)
        .forward(side_length_)
        .penup()
        .right(180)
        .forward(side_length_ / 2)
        .left(90)
        .forward(side_length_ / 2)
        .right(180)
        .pendown()
        .forward(side_length_)
        .left(90);
}
