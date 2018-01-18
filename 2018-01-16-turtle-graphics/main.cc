#include <iostream>

#include "ps_turtle.hh"

using namespace std;

int main() {
    PSTurtle t(500, 500);

    t.setup()
    .pendown()
    .pencolor(Color(0.5, 0.35, 0.75))
    .pensize(10.0)
    .forward(100)
    .left(90).forward(100)
    .left(90).forward(100)
    .left(90).forward(100);

    return 0;
}
