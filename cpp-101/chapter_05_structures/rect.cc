#include <iostream>

using namespace std;

struct point {
    double x;
    double y;
};

struct rect {
    point bottom_left;
    point upper_right;
};

inline double min(double x, double y);
inline double max(double x, double y);
rect canonical_rect(rect r);
bool contains(rect r, point p);

int main() {
    point bl = {3.5, 2.5};
    point ur = {2.4, 3.0};

    rect r = {bl, ur};
    rect cr = canonical_rect(r);

    return 0;
}

inline double min(double x, double y) {
    return x < y ? x : y;
}

inline double max(double x, double y) {
    return x > y ? x : y;
}

rect canonical_rect(rect r) {
    point bl = {min(r.bottom_left.x, r.upper_right.x), min(r.bottom_left.y, r.upper_right.y)};
    point ur = {max(r.bottom_left.x, r.upper_right.x), max(r.bottom_left.y, r.upper_right.y)};

    rect result = {bl, ur};

    return result;
}

bool contains(rect r, point p) {
    return (p.x >= r.bottom_left.x && p.x <= r.upper_right.x) &&
           (p.y >= r.bottom_left.y && p.y <= r.upper_right.y);
}
