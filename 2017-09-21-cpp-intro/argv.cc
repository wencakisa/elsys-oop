#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    for (int i = 0; i < argc; ++i) {
        cout << "args[" << i << "] = " << argv[i] << endl;
    }

    return 0;
}
