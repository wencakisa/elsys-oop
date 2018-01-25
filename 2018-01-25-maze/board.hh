#ifndef BOARD_HH_
#define BOARD_HH_

#include <vector>

#include "cell.hh"
#include "turtle.hh"

class Board {
    const int height_;
    const int width_;
    std::vector<Cell> board_;
public:
    Board(int height, int width);

    Cell get_cell(int row, int col) const;

    void draw(Turtle& t);
};

#endif
