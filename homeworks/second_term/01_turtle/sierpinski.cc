// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: sierpinski.cc
// FILE PURPOSE:
//     Implementation of the Sierpinski curve
//     defined in ./sierpinski.hh
// -------------------------------------------

#include "sierpinski.hh"

Sierpinski::Sierpinski(Turtle* turtle, int side_length, const Point& center, int order)
: Figure(turtle, side_length, center), step_(0), order_(order)
{}

Sierpinski::~Sierpinski() {
    delete turtle_;
}

double Sierpinski::calculate_step(int order) {
	assert(order > 0);

	double step = side_length_;
	while (--order > 0) {
		step /= 2.0;
	}

	step_ = step;

	return step;
}

void Sierpinski::draw_a(int order) {
	assert(order >= 0);

	if (order == 0) {
		return;
	} else {
		draw_a(order - 1);
		turtle_->set_heading(-45).forward(step_);
		draw_b(order - 1);
		turtle_->set_heading(0).forward(step_ * 2);
		draw_d(order - 1);
		turtle_->set_heading(45).forward(step_);
		draw_a(order - 1);
	}
}

void Sierpinski::draw_b(int order) {
	assert(order >= 0);

	if (order == 0) {
		return;
	} else {
		draw_b(order - 1);
		turtle_->set_heading(-135).forward(step_);
		draw_c(order - 1);
		turtle_->set_heading(-90).forward(step_ * 2);
		draw_a(order - 1);
		turtle_->set_heading(-45).forward(step_);
		draw_b(order - 1);
	}
}

void Sierpinski::draw_c(int order) {
	assert(order >= 0);

	if (order == 0) {
		return;
	} else {
		draw_c(order - 1);
		turtle_->set_heading(135).forward(step_);
		draw_d(order - 1);
		turtle_->set_heading(180).forward(step_ * 2);
		draw_b(order - 1);
		turtle_->set_heading(-135).forward(step_);
		draw_c(order - 1);
	}
}

void Sierpinski::draw_d(int order) {
	assert(order >= 0);

	if (order == 0) {
		return;
	} else {
		draw_d(order - 1);
		turtle_->set_heading(45).forward(step_);
		draw_a(order - 1);
		turtle_->set_heading(90).forward(step_ * 2);
		draw_c(order - 1);
		turtle_->set_heading(135).forward(step_);
		draw_d(order - 1);
	}
}

void Sierpinski::draw() {
    calculate_step(order_);

    Point p0 = center_;
    p0 = p0 + Point(-side_length_ * 2, side_length_ * 2);

    turtle_->moveto(p0).pendown();

    draw_a(order_);
    turtle_->set_heading(-45).forward(step_);
    draw_b(order_);
    turtle_->set_heading(-135).forward(step_);
    draw_c(order_);
    turtle_->set_heading(135).forward(step_);
    draw_d(order_);
    turtle_->set_heading(45).forward(step_);
}
