#include "star.hh"

Star::Star(Turtle* turtle, int side_length, const Point& center)
: Figure(turtle, side_length, center)
{}

void Star::draw() {
    turtle_->penup()
        .moveto(center_)
        .pencolor(Color(0, 1, 0))
        .left(90)
        .forward(side_length_)
        .left(60)
        .pendown();


    for (int i = 0; i < SIDES_; ++i) {
        turtle_->forward(side_length_).left(120).forward(side_length_).right(60);
    }
}
