#include "turtle.hh"

Turtle::Turtle(double width, double height)
: width_(width), height_(height),
  pos_(width / 2.0, height / 2.0),
  heading_(0),
  is_pendown_(false),
  pensize_(1),
  pencolor_(Color::gray(0.5))
{}

Turtle::~Turtle() {}

Turtle& Turtle::setup() {
    return *this;
}

double Turtle::get_width() const {
    return width_;
}

double Turtle::get_height() const {
    return height_;
}

Point Turtle::get_pos() const {
    return pos_;
}

double Turtle::get_heading() const {
    return heading_;
}

bool Turtle::is_pendown() const {
    return is_pendown_;
}

double Turtle::get_pensize() const {
    return pensize_;
}

Color Turtle::get_color() const {
    return pencolor_;
}

Turtle& Turtle::set_pos(const Point& p) {
    pos_ = p;

    return *this;
}

Turtle& Turtle::set_heading(double angle) {
    heading_ = angle;

    return *this;
}

Turtle& Turtle::pensize(double width) {
    pensize_ = width;

    return *this;
}

Turtle& Turtle::pencolor(const Color& c) {
    pencolor_ = c;

    return *this;
}

Turtle& Turtle::penup() {
    is_pendown_ = false;

    return *this;
}

Turtle& Turtle::pendown() {
    is_pendown_ = true;

    return *this;
}

Turtle& Turtle::right(double angle) {
    heading_ -= angle;

    return *this;
}

Turtle& Turtle::left(double angle) {
    heading_ += angle;

    return *this;
}

Turtle& Turtle::moveto(const Point& pos) {
    pos_ = pos;

    return *this;
}

Turtle& Turtle::forward(double distance) {
    Point movement = Point::polar(heading_, distance);
    Point next_pos = get_pos() + movement;

    moveto(next_pos);

    return *this;
}

Turtle& Turtle::backward(double distance) {
    return forward(-distance);
}
