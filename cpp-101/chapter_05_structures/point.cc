#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
};

void print_point(point p);
double distance(point p1, point p2);
point add(point p1, point p2);
point subtract(point p1, point p2);

int main() {
    point p1 = {3.5, 2.5};
    point p2 = {2.0, 4.7};

    print_point(p1);
    print_point(p2);

    cout << distance(p1, p2) << endl;
    print_point(add(p1, p2));
    print_point(subtract(p1, p2));

    return 0;
}

void print_point(point p) {
    cout << "(" << p.x << "; " << p.y << ")" << endl;
}

double distance(point p1, point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

point add(point p1, point p2) {
    point result = {p1.x + p2.x, p1.y + p2.y};

    return result;
}

point subtract(point p1, point p2) {
    point result = {p1.x - p2.x, p1.y - p2.y};

    return result;
}
