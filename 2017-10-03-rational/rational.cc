#include <iostream>

using namespace std;

int gcd(int number1, int number2) {
    while (number1 != number2) {
        if (number1 > number2) {
            number1 -= number2;
        } else {
            number2 -= number1;
        }
    }

    return number1;
}

class Rational {
    int numerator_;
    int denominator_;
public:
    Rational(int numerator, int denominator) {
        int divisor = gcd(numerator, denominator);
        numerator_ = numerator / divisor;
        denominator_ = denominator / divisor;
    }

    int get_numerator() {
        return numerator_;
    }

    void set_numerator(int numerator) {
        numerator_ = numerator;
    }

    int get_denominator() {
        return denominator_;
    }

    void set_denominator(int denominator) {
        denominator_ = denominator;
    }
    bool is_equal(Rational other) {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }

    Rational operator+(const Rational& r) {
        return Rational(
            numerator_ * r.denominator_ + r.numerator_ * denominator_,
            denominator_ * r.denominator_
        );
    }

    friend ostream& operator<<(ostream& stream, const Rational& r) {
        stream << r.numerator_ << " / " << r.denominator_;
        return stream;
    }
};

int main() {
    Rational r1(1, 2), r2(3, 5);

    cout << r1.is_equal(r2) << endl;

    Rational result = r1 + r2;
    cout << result << endl;

    return 0;
}
