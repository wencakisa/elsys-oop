#include "hexagon.hh"

Hexagon::Hexagon(Turtle* turtle, int side_length, const Point& center)
: Figure(turtle, side_length, center)
{}

void Hexagon::draw() {
    turtle_->penup()
        .moveto(center_)
        .pencolor(Color(1, 0, 0))
        .left(90)
        .forward(side_length_)
        .left(120)
        .pendown();

    for (int i = 0; i < SIDES_; ++i) {
        turtle_->forward(side_length_).left(60);
    }
}