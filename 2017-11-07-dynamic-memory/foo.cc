#include <iostream>
#include <cstdlib>

using namespace std;

class Foo {
    int bar_;
public:
    Foo() : bar_(0) {
        cout << "Initialized." << endl;
    }

    int get_bar() {
        return bar_;
    }
};

int main() {
    Foo* ptr = new Foo();
    // Foo *ptr = (Foo*) malloc(sizeof(Foo));
    cout << ptr->get_bar() << endl;
    delete ptr;
    // free(ptr);

    return 0;
}
