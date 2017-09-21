#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int sum = 0;

    for (int i = 1; i < argc; ++i) {
        sum += strtol(argv[i], NULL, 10);
    }

    cout << "Sum of integer command line arguments = " << sum << endl;

    return 0;
}
