#include <cstdlib>
#include <iostream>

using namespace std;

class Stack {
    const static int chunk_ = 2;
    int top_;
    int size_;
    int *data_;

public:
    Stack() : top_(0), size_(chunk_), data_(new int[chunk_]) {
        cout << "Default constructor called" << endl;
    }

    Stack(const Stack& other)
        : top_(other.top_), size_(other.size_), data_(new int[other.size_]) {
        cout << "Copy constructor called" << endl;
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    ~Stack() {
        cout << "Desctructor called" << endl;
        delete [] data_;
    }

    Stack& operator=(const Stack& other) {
        cout << "Copy assignment operator called" << endl;

        if (this != &other) {
            delete [] data_;

            top_ = other.top_;
            size_ = other.size_;
            data_ = new int[size_];

            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }

        return *this;
    }

    bool empty() const {
        return top_ == 0;
    }

    bool full() const {
        return top_ == size_;
    }

    int get_top() const {
        return top_;
    }

    int length() const {
        return get_top();
    }

    void push(int val) {
        if (full()) {
            cout << "Stack full! Resizing ..." << endl;
            resize();
        }

        data_[top_++] = val;
    }

    int pop() {
        if (empty()) {
            throw exception();
        }

        return data_[--top_];
    }

private:
    void resize() {
        int *tmp = data_;
        data_ = new int[size_ + chunk_];

        for (size_t i = 0; i < size_; i++) {
            data_[i] = tmp[i];
        }
        size_ += chunk_;

        delete [] tmp;
    }
};

double average(Stack st) {
    int length = st.length();
    int sum = 0;

    while (!st.empty()) {
        sum += st.pop();
    }

    return ((double) sum) / length;
}

int main() {
    Stack st;

    for (size_t i = 0; i < 10; i++) {
        st.push(i);
    }

    cout << "Average: " << average(st) << endl;

    try {
        Stack st2;
        st2 = st;

        st2.push(1000);
        cout << st2.pop() << endl;
        cout << st2.pop() << endl;
        cout << st2.pop() << endl;

    } catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
