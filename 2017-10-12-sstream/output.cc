#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ostringstream out;
    out << 3.14 << " " << 42 << "Hello" << " " << "World!" << "!";

    string s = out.str();

    cout << "String: " << s << endl;

    return 0;
}
