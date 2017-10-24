#include <iostream>

using namespace std;

class Point {
    double x_, y_;
public:
    Point(double x=0.0, double y=0.0) : x_(x), y_(y) {}

    double get_x() const {
        return x_;
    }

    Point& set_x(double x) {
        x_ = x;

        return *this;
    }

    double get_y() const {
        return y_;
    }

    Point& set_y(double y) {
        y_ = y;

        return *this;
    }

    Point operator-(void) const {
        return Point(-x_, -y_);
    }

    Point& operator+=(const Point& other) {
        x_ += other.x_;
        y_ += other.y_;

        return *this;
    }

    Point& operator-=(const Point& other) {
        x_ -= other.x_;
        y_ -= other.y_;

        return *this;
    }

    Point& operator*=(const double alpha) {
        x_ *= alpha;
        y_ *= alpha;

        return *this;
    }
};

Point operator+(const Point& p1, const Point& p2) {
    Point result = p1;
    result += p2;

    return result;
}

Point operator-(const Point& p1, const Point& p2) {
    Point result = p1;
    result -= p2;

    return result;
}

Point operator*(const Point& p, double alpha) {
    Point result = p;
    result *= alpha;

    return result;
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.get_x() << "; " << p.get_y() << ")";

    return out;
}

int main() {
    Point p1, p2(3, 5);

    Point p3 = p1 + p2;
    cout << p3 << endl;

    p3 *= 2;
    cout << p3 << endl;

    p3 = -p2;
    cout << p3 << endl;

    return 0;
}
