#include <iostream>

#include "ps_turtle.hh"
#include "board.hh"

using namespace std;

int main() {
    PSTurtle t(1000, 1000);
    t.setup();

    Board b(30, 30);
    b.draw(t);

    return 0;
}
