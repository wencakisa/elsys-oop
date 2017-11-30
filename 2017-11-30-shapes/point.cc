#include "point.hh"

using namespace std;

ostream& operator<<(ostream& out, const Point& p) {
    out << "Point(" << p.get_x() << "; " << p.get_y() << ")";
    return out;
}
