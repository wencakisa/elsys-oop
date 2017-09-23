#include <iostream>

using namespace std;

struct person {
    char* name;
    int age;
};

void print_person(person p);

int main() {
    char name[] = "Pesho";
    person p = {name, 18};

    print_person(p);

    return 0;
}

void print_person(person p) {
    cout << p.name << " (" << p.age << ")" << endl;
}
