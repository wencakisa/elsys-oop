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

    void generate_maze(Cell& c);

private:
    Cell* get_neighbour(Cell* c, Direction dir);
    std::vector<Direction> get_unvisited_neighbours(Cell* c);
    Cell* drill(Cell* c, Direction dir);
};

#endif
