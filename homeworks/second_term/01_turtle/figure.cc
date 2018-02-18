#include "figure.hh"

Figure::Figure(Turtle* turtle, int side_length, const Point& center)
: turtle_(turtle), side_length_(side_length), center_(center)
{
    if (!turtle_->is_setup()) {
        turtle_->setup();
    }
}
