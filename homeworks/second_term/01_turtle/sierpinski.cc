#include "sierpinski.hh"

Sierpinski::Sierpinski(int level, Turtle* turtle, int side_length, const Point& center)
: Figure(turtle, side_length, center), level_(level)
{}

Sierpinski::~Sierpinski() {
    delete turtle_;
}

void Sierpinski::left(int level) {

}

void Sierpinski::right(int level) {

}

void Sierpinski::draw() {
    turtle_->penup()
        .right(90)
        .forward(side_length_)
        .pendown();

    for (int i = 0; i < 8; ++i) {
        turtle_->forward(side_length_).right(45).forward(side_length_).left(90);
    }
    // .forward(side_length_)
    // .left(45)
    // .forward(side_length_)
    // .right(90)
    // .forward(side_length_)
    // .right(90)
    // .forward(side_length_)
    // .left(45)
    // .forward(side_length_ * 2)
    // .left(45)
    // .forward(side_length_)
    // .right(90)
    // .forward(side_length_)
    // .right(90)
    // .forward(side_length_)
    // .left(45)
    // .forward(side_length_);
}
