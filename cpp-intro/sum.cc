#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int val = 0;

    while (true) {
        cin >> val;

        if (!cin.good()) {
            break;
        }

        sum += val;
    }

    cout << "Sum is " << sum << endl;

    return 0;
}
