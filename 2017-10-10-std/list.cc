#include <iostream>
#include <list>

using namespace std;

void print_list(list<int>& l) {
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    list<int> l;

    cout << "Size: " << l.size() << endl;
    cout << "Empty: " << l.empty() << endl;

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);

    cout << "Size: " << l.size() << endl;
    cout << "Empty: " << l.empty() << endl;
    print_list(l);

    l.push_front(-1);
    cout << "Size: " << l.size() << endl;
    print_list(l);

    cout << "Front: " << l.front() << endl;
    cout << "Back: " << l.back() << endl;
    print_list(l);

    l.insert(l.begin(), -2);
    l.insert(l.end(), 3);
    print_list(l);

    auto it = l.begin();
    it++;
    l.insert(it, -1);
    print_list(l);

    // cout << l[0] << endl;
    it = l.begin();
    it++;
    l.erase(it);
    print_list(l);

    l.erase(l.begin(), l.end());
    cout << "Empty: " << l.empty() << endl;

    list<int> l1(10);
    print_list(l1);

    list<int> l2(10, 42);
    print_list(l2);

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l3(a, a + 10);
    print_list(l3);

    return 0;
}
