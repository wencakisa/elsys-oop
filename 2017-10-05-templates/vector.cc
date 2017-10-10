#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vector_info(vector<T>);

int main() {
    vector<int> vi;

    print_vector_info(vi);
    vi.push_back(0);
    print_vector_info(vi);
    vi.push_back(1);
    print_vector_info(vi);
    vi.push_back(2);
    print_vector_info(vi);
    vi.push_back(3);
    print_vector_info(vi);

    vi.at(0) = 42;

    for (size_t i = 0; i < vi.size(); i++) {
        cout << "vi[" << i << "] = " << vi[i] << endl;
    }

    vector<double> vd(100);
    print_vector_info(vd);

    for (size_t i = 0; i < vd.size(); i++) {
        vd[i] = i * 3.14;
    }

    vd.push_back(vd.size() * 3.14);
    print_vector_info(vd);

    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        cout << "*it = " << *it << endl;
    }

    for (auto it = vi.begin(); it != vi.end(); ++it) {
        cout << "*it = " << *it << endl;
    }

    return 0;
}

template <typename T> void print_vector_info(vector<T> v) {
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Empty: " << (bool) v.empty() << endl;
}
