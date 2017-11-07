#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <iomanip>

using namespace std;

#define STOP_WORD "END"
#define STRICT_OPTION    "strict"
#define INTS_ONLY_OPTION "integers-only"
#define PRECISION 4

class Exception {
    string message_;
public:
    Exception(string msg) : message_(msg) {}

    string get_msg() const {
        return message_;
    }
};

bool contains(string haystack, string needle) {
    return haystack.find(needle) != string::npos;
}

double get_sum(list<double>& l) {
    double result = 0.0;

    for (auto it = l.begin(); it != l.end(); ++it) {
        result += *it;
    }

    return result;
}

double get_avg(list<double>& l, bool as_int) {
    double avg = get_sum(l) / l.size();

    return as_int ? (int) avg : avg;
}

int main() {
    try {
        string token;
        list<double> values;

        bool options_set = false;
        bool strict = false, ints_only = false;

        while (true) {
            cin >> token;

            if (token == STOP_WORD) {
                break;
            }

            istringstream in(token);
            double value;
            in >> value;

            if (!in.fail() && in.eof()) {
                if (ints_only) {
                    if (strict && value != (int) value) {
                        throw Exception("PROVIDE ONLY INTEGERS");
                    }

                    value = (int) value;
                }

                values.push_back(value);
            } else {
                if (strict) {
                    throw Exception("PROVIDE ONLY NUMBERS");
                }

                if (!options_set) {
                    strict = contains(token, STRICT_OPTION);
                    ints_only = contains(token, INTS_ONLY_OPTION);
                }
            }

            options_set = true;
        }

        if (values.empty()) {
            throw Exception("PROVIDE AT LEAST ONE NUMBER");
        }

        values.sort();
        double min = values.front();
        double max = values.back();
        double avg = get_avg(values, ints_only);

        cout << min << " " << max << " " << setprecision(PRECISION) << avg << endl;
    } catch (Exception ex) {
        cout << "ERR: " << ex.get_msg() << endl;
        return 1;
    }

    return 0;
}
