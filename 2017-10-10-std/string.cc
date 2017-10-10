#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2("World!");
    string s3 = " ";

    string s = s1 + s3 + s2;
    cout << s << endl;

    for (size_t i = 0; i < s.length(); ++i) {
        cout << "s[" << i << "] = " << s[i] << endl;
    }

    string search = "Wo";
    auto pos = s.find(search);
    if (pos != string::npos) {
        cout << "Position: " << pos << endl;
        cout << s.substr(pos, search.length()) << endl;
    } else {
        cout << "Substring not found!" << endl;
    }

    pos = 0;
    while ((pos = s.find("l", pos)) != string::npos) {
        cout << s.substr(pos, 1) << endl;
        pos++;
    }

    return 0;
}
