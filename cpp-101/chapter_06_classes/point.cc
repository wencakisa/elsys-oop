#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x_, y_;
public:
    double get_x() { return x_; }
    double get_y() { return y_; }

    void set_x(double x) { x_ = x; }
    void set_y(double y) { y_ = y; }

    Point(double x=0.0, double y=0.0) {
        set_x(x);
        set_y(y);
    }

    void add(Point other) {
        set_x(get_x() + other.get_x());
        set_y(get_y() + other.get_y());
    }

    void sub(Point other) {
        set_x(get_x() - other.get_x());
        set_y(get_y() - other.get_y());
    }

    double distance(Point other) {
        double dx = get_x() - other.get_x();
        double dy = get_y() - other.get_y();

        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    void print() {
        cout << "(" << x_ << "; " << y_ << ")" << endl;
    }
};

Point add(Point, Point);
Point sub(Point, Point);
double distance(Point, Point);

int main() {
    Point p1 = Point();
    Point p2 = Point(1.0, 2.5);

    p1.print();
    p2.print();

    Point p3 = add(p1, p2);
    p3.print();

    Point p4 = sub(p1, p2);
    p4.print();

    cout << distance(p3, p4) << endl;

    return 0;
}

Point add(Point p1, Point p2) {
    Point result = p1;
    result.add(p2);

    return result;
}

Point sub(Point p1, Point p2) {
    Point result = p1;
    result.sub(p2);

    return result;
}

double distance(Point p1, Point p2) {
    return p1.distance(p2);
}
