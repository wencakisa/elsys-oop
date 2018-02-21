// -------------------------------------------
// NAME: Vencislav Tashev
// CLASS: XIa
// NUMBER: 4
// PROBLEM: #1
// FILE NAME: figure.hh
// FILE PURPOSE:
//     Implementation of the base figure class
//
//     Only the class' constructor is
//     implemented in this file.
// -------------------------------------------


#include "figure.hh"

Figure::Figure(Turtle* turtle, int side_length, const Point& center)
: turtle_(turtle), side_length_(side_length), center_(center)
{
    if (!turtle_->is_setup()) {
        turtle_->setup();
    }
}
