#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string token;

    while (true) {
        cin >> token;

        if (token == "EXIT") {
            break;
        }

        if (!cin.good()) {
            break;
        }

        cout << "Token: <" << token << ">" << endl;

        istringstream in(token);
        double val;
        in >> val;

        if (!in.fail() && in.eof()) {
            cout << "Success: " << val << endl;
        } else {
            cout << "Cannot convert string <" << token << "> to double." << endl;
        }
    }

    return 0;
}
