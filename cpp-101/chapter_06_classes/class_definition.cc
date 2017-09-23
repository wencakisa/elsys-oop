#include <iostream>

using namespace std;

class Point {
    double x_;
    double y_;
};

class Rectangle {
    Point bl_, ur_;
};

class Foo {
    int bar_ = 42; // Results in an error.
};

int main() {

    return 0;
}
