#include <iostream>

using namespace std;

class Point {
private:
    double x_, y_;

public:
    void set_x(double x) { x_ = x; }
    double get_x() { return x_; }
};

int main() {
    Point p1, p2;

    p1.set_x(5.3);
    p2.set_x(4.7);

    cout << p1.get_x() << endl;
    cout << p2.get_x() << endl;

    return 0;
}
