#include <iostream>

using namespace std;

int main() {
    char ch;

    while (true) {
        cin.get(ch);

        if (!cin.good()) {
            cerr << "Program stopped!" << endl;
            break;
        }

        cout << ch;
    }

    return 0;
}
