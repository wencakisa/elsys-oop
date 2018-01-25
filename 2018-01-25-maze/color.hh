#ifndef COLOR_HH_
#define COLOR_HH_

#include <iostream>

class Color {
    double r_, g_, b_;
public:
    Color(double r = 0.0, double g = 0.0, double b = 0.0);

    double red() const;
    double green() const;
    double blue() const;

    static Color gray(double gray);
};

std::ostream& operator<<(std::ostream& out, const Color& c);

#endif
