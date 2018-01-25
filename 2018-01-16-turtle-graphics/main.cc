#include <iostream>

#include "ps_turtle.hh"

using namespace std;

int main() {
    PSTurtle turtle(500, 500);

    turtle.setup()
        .pendown()
        .pensize(5.0)
        .pencolor(Color::gray(0.5))
        .forward(100);

    return 0;
}
