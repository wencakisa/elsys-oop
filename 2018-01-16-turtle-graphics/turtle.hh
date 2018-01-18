#ifndef TURTLE_HH_
#define TURTLE_HH_

#include "point.hh"
#include "color.hh"

class Turtle {
    double width_, height_;
    Point pos_;
    double heading_;
    bool is_pendown_;
    double pensize_;
    Color pencolor_;
public:
    Turtle(double width, double height);

    virtual ~Turtle();
    virtual Turtle& setup();

    bool is_setup() const;

    // Getters
    double get_width() const;
    double get_height() const;

    Point get_pos() const;

    double get_heading() const;

    bool is_pendown() const;

    double get_pensize() const;
    Color get_color() const;

    // Setters
    Turtle& set_pos(const Point& p);
    Turtle& set_heading(double angle);

    // Overridable setters for pen size and color
    virtual Turtle& pensize(double width = 1.0);
    virtual Turtle& pencolor(const Color& c);

    Turtle& penup();
    Turtle& pendown();

    Turtle& right(double angle);
    Turtle& left(double angle);

    virtual Turtle& moveto(const Point& pos);

    Turtle& forward(double distance);
    Turtle& backward(double distance);

    virtual Turtle& dot(double size = 1.0);
};

#endif
