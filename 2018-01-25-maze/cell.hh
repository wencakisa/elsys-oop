#ifndef CELL_HH_
#define CELL_HH_

#include "direction.hh"
#include "turtle.hh"

class Cell {
    static const int STEP_ = 30;

    bool visited_;
    bool walls_[ALL];
    int row_;
    int col_;
public:
    Cell(int row, int col);

    // -----------------------------------------

    bool is_visited() const;
    bool has_wall(Direction dir) const;

    // -----------------------------------------

    Cell& visit();

    // -----------------------------------------

    Cell& drill_wall(Direction dir);
    Cell& build_wall(Direction dir);

    // -----------------------------------------

    void draw(Turtle& t);
};

#endif
