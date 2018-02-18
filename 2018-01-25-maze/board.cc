#include <vector>
#include <cassert>
#include <cstdlib>

#include "board.hh"

using namespace std;

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

void Board::generate_maze(Cell& c) {
    c.visit();

    while (true) {
        vector<Direction> neighbours = get_unvisited_neighbours(&c);

        if (neighbours.empty()) {
            break;
        }

        int random = rand() % neighbours.size();
        Direction random_dir = neighbours[random];

        Cell* neighbour = drill(&c, random_dir);

        generate_maze(*neighbour);
    }
}

Cell* Board::get_neighbour(Cell* c, Direction dir) {
    int row = c->row();
    int col = c->col();

    switch (dir) {
        case UP:
            row++;
            break;
        case DOWN:
            row--;
            break;
        case LEFT:
            col--;
            break;
        case RIGHT:
            col++;
            break;
        default:
            assert(false);
    }

    if (row < 0 || row >= height_ || col < 0 || col >= width_) {
        return NULL;
    }

    return &get_cell(row, col);
}

vector<Direction> Board::get_unvisited_neighbours(Cell* c) {
    vector<Direction> result;

    for (int i = 0; i < ALL; ++i) {
        Cell* neighbour = get_neighbour(c, (Direction) i);;

        if (neighbour != NULL) {
            if (!neighbour->is_visited()) {
                result.push_back((Direction) i);
            }
        }
    }

    return result;
}

Cell* Board::drill(Cell* c, Direction dir) {
    Cell* neighbour = get_neighbour(c, dir);

    assert(neighbour != NULL);

    c->drill_wall(dir);
    neighbour->drill_wall((Direction)((dir + 2) % 4));

    return neighbour;
}
