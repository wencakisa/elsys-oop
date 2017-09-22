#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int v[] = {1, 2, 3, 4};

    int *p = v;
    int *begin = &v[0];
    int *end = &v[4];

    cout << p << endl;
    cout << begin << endl;
    cout << end << endl;

    return 0;
}
