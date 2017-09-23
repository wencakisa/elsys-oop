#include <iostream>

using namespace std;
/*
    Now we can understand why we write
        using namespace std;
    so often.

        cout
        cin
        cerr
    and many more streams and functions
    are defined in the *standard* (std) namespace
*/

namespace elsys {
    class School {

    };
    class Student {

    };
    class Teacher {

    };
}

int main() {
    elsys::Teacher full;   // full accessing of namespace members

    using elsys::School;   // using specific member
    // Teacher t;
    School s;

    using namespace elsys; // using the whole namespace
    School sch;
    Student st;

    cout << "Hello World!" << endl;

    return 0;
}
