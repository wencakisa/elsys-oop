#include "point.hh"

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.get_x() << "; " << p.get_y() << ")";
    return out;
}
