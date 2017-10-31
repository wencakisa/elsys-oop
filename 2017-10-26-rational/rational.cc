#include <iostream>

using namespace std;

long gcd(long a, long b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

class IllegalArgumentException {
    string message_;
public:
    IllegalArgumentException(string message) : message_(message) {}

    string get_msg() const {
        return message_;
    }
};

class Rational {
    long num_, den_;
public:
    Rational(long numerator=0, long denominator=1) {
        set_numerator(numerator).set_denominator(denominator).normalize();
    }

    void normalize() {
        long divisor = gcd(num_, den_);
        num_ /= divisor;
        den_ /= divisor;

        if (num_ > 0 && den_ < 0) {
            num_ *= -1;
            den_ *= -1;
        }
    }

    void reverse() {
        swap(num_, den_);
    }

    long get_numerator() const {
        return num_;
    }

    Rational& set_numerator(long numerator) {
        num_ = numerator;

        return *this;
    }

    long get_denominator() const {
        return den_;
    }

    Rational& set_denominator(long denominator) {
        if (denominator == 0) {
            throw IllegalArgumentException("Denominator can't be zero.");
        }

        den_ = denominator;

        return *this;
    }

    Rational& add(const Rational& r) {
        num_ *= r.den_;
        num_ += den_ * r.num_;
        den_ *= r.den_;

        normalize();

        return *this;
    }

    Rational& sub(const Rational& r) {
        num_ *= r.den_;
        num_ -= den_ * r.num_;
        den_ *= r.den_;

        normalize();

        return *this;
    }

    Rational& mul(const Rational& r) {
        num_ *= r.num_;
        den_ *= r.den_;

        normalize();

        return *this;
    }

    Rational& div(const Rational& r) {
        Rational r_copy = r;
        r_copy.reverse();

        return mul(r_copy);
    }

    Rational& operator+=(const Rational& r) { return add(r); }
    Rational& operator-=(const Rational& r) { return sub(r); }
    Rational& operator*=(const Rational& r) { return mul(r); }
    Rational& operator/=(const Rational& r) { return div(r); }
};

Rational operator+(const Rational& r1, const Rational& r2) {
    Rational result = r1;
    result += r2;

    return result;
}

Rational operator-(const Rational& r1, const Rational& r2) {
    Rational result = r1;
    result -= r2;

    return result;
}

Rational operator*(const Rational& r1, const Rational& r2) {
    Rational result = r1;
    result *= r2;

    return result;
}

Rational operator/(const Rational& r1, const Rational& r2) {
    Rational result = r1;
    result /= r2;

    return result;
}

istream& operator>>(istream& in, Rational& r) {
    char ch = 0;
    long numerator = 0, denominator = 1;

    in >> numerator;

    in >> ch;
    if (ch != '/') {
        in.clear(ios_base::badbit);
        return in;
    }

    in >> denominator;

    if (in.good()) {
        r.set_numerator(numerator).set_denominator(denominator).normalize();
    }

    return in;
}

ostream& operator<<(ostream& out, const Rational& r) {
    out << "(" << r.get_numerator() << "/" << r.get_denominator() << ")";

    return out;
}

int main() {
    try {
        Rational r1, r2;

        cout << "Enter first rational: ";
        cin >> r1;

        cout << "Enter second rational: ";
        cin >> r2;

        Rational result = r1 + r2;
        cout << r1 << " + " << r2 << " = " << result << endl;

        result = r1 - r2;
        cout << r1 << " - " << r2 << " = " << result << endl;

        result = r1 * r2;
        cout << r1 << " * " << r2 << " = " << result << endl;

        result = r1 / r2;
        cout << r1 << " / " << r2 << " = " << result << endl;

    } catch (IllegalArgumentException ex) {
        cout << ex.get_msg() << endl;
        return -1;
    }

    return 0;
}
