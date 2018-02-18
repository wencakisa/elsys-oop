#include <iostream>

#include "ps_turtle.hh"
#include "board.hh"

using namespace std;

int main() {
    PSTurtle t(1000, 1000);
    t.setup().penup();

    Board b(30, 30);

    Cell& start = b.get_cell(0, 0);
    b.generate_maze(start);
    b.draw(t);

    return 0;
}
