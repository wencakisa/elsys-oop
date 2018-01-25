#include "board.hh"

Board::Board(int height, int width)
: height_(height), width_(width)
{
    for (int row = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            board_.push_back(Cell(row, col));
        }
    }
}

Cell Board::get_cell(int row, int col) const {
    int index = row * width_ + col;

    return board_.at(index);
}

void Board::draw(Turtle& t) {
    for (Cell& c : board_) {
        c.draw(t);
    }
}
