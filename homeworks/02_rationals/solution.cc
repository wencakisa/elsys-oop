#include <iostream>
#include <list>
#include <sstream>

using namespace std;

#define STOP_WORD "q"
#define OPERATOR_PLUS_SYMBOL '+'
#define OPERATOR_MINUS_SYMBOL '-'
#define OPERATOR_MULTIPLY_SYMBOL '*'
#define OPERATOR_DIVIDE_SYMBOL '/'

long gcd(long a, long b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

template<class T>
T get_and_remove_element(list<T>& collection) {
    T result = collection.front();
    collection.pop_front();

    return result;
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

    in >> ch;
    if (ch != '(') {
        in.clear(ios_base::badbit);
        return in;
    }

    in >> numerator;

    in >> ch;
    if (ch != '/') {
        in.clear(ios_base::badbit);
        return in;
    }

    in >> denominator;

    in >> ch;
    if (ch != ')') {
        in.clear(ios_base::badbit);
        return in;
    }

    if (in.good()) {
        r.set_numerator(numerator).set_denominator(denominator).normalize();
    }

    return in;
}

ostream& operator<<(ostream& out, const Rational& r) {
    out << "(" << r.get_numerator() << "/" << r.get_denominator() << ")";

    return out;
}

class Expression {
    list<Rational> operands_;
    list<char> operators_;

    Rational result_;

public:
    Expression& add_operand(Rational operand) {
        operands_.push_back(operand);

        return *this;
    }

    Expression& add_operator(char op) {
        operators_.push_back(op);

        return *this;
    }

    Rational get_result() const {
        return result_;
    }

    void evaluate() {
        while (operands_.size() > 1) {
            Rational result = calculate_latest();
            operands_.push_front(result);

            set_result(result);
        }

        operands_.clear();
        operators_.clear();
    }

private:
    Expression& set_result(Rational& val) {
        result_ = val;

        return *this;
    }

    Rational calculate_latest() {
        Rational left_operand = get_and_remove_element(operands_);
        char op = get_and_remove_element(operators_);
        Rational right_operand = get_and_remove_element(operands_);

        switch (op) {
            case OPERATOR_PLUS_SYMBOL:
                return left_operand + right_operand;
            case OPERATOR_MINUS_SYMBOL:
                return left_operand - right_operand;
            case OPERATOR_MULTIPLY_SYMBOL:
                return left_operand * right_operand;
            case OPERATOR_DIVIDE_SYMBOL:
                return left_operand / right_operand;
            default:
                throw IllegalArgumentException("Invalid operator");
        }
    }
};

int main() {
    string token;
    Expression expr;
    list<Expression> expressions;

    try {
        while (true) {
            cin >> token;

            if (token == STOP_WORD) {
                break;
            }

            istringstream in(token);
            Rational rational;
            in >> rational;

            if (!in.fail()) {
                expr.add_operand(rational);
            } else {
                char op = in.str().at(0);

                if (op == '=') {
                    expr.evaluate();
                    expressions.push_back(expr);
                } else {
                    expr.add_operator(op);
                }
            }
        }

        for (auto it = expressions.begin(); it != expressions.end(); ++it) {
            cout << "> " << (*it).get_result() << endl;
        }
        cout << "> " << endl;

    } catch (IllegalArgumentException ex) {
        cout << ex.get_msg() << endl;
        return -1;
    }

    return 0;
}
