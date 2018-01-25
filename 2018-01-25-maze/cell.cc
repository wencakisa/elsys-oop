#include <algorithm>

#include "cell.hh"

Cell::Cell(int row, int col)
: visited_(false),
  row_(row),
  col_(col)
{
    std::fill_n(walls_, ALL, true);
}

// -----------------------------------------

bool Cell::is_visited() const {
    return visited_;
}

bool Cell::has_wall(Direction dir) const {
    return walls_[dir];
}

// -----------------------------------------

Cell& Cell::visit() {
    visited_ = true;

    return *this;
}

// -----------------------------------------

Cell& Cell::drill_wall(Direction dir) {
    walls_[dir] = false;

    return *this;
}

Cell& Cell::build_wall(Direction dir) {
    walls_[dir] = true;

    return *this;
}

// -----------------------------------------

void Cell::draw(Turtle& t) {
    t.set_pos(Point((col_ + 1) * STEP_, (row_ + 1) * STEP_)).set_heading(0);

    for (int i = 0; i < ALL; ++i) {
        if (has_wall((Direction) i)) {
            t.pendown();
        } else {
            t.penup();
        }

        t.forward(STEP_).left(90);
    }
}
