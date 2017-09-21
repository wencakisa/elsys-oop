#include <iostream>

using namespace std;

int main() {
    int answer = -1;

    cout << "Enter answer: ";
    cin >> answer;

    if (cin.good()) {
        cout << "Answer: " << answer << endl;
    } else {
        cerr << "Something went wrong!" << endl;
    }

    return 0;
}
