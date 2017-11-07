#include <iostream>
#include <exception>

using namespace std;

class Stack {
    const static int chunk_ = 2;
    int size_;
    int *data_;
    int top_;

public:
    Stack() : size_(chunk_), data_(new int[chunk_]), top_(0) {}

    ~Stack() {
        cout << "Destructor called" << endl;
        delete [] data_;
    }

    bool is_full() const {
        return top_ == size_;
    }

    bool is_empty() const {
        return top_ == 0;
    }

    void push(int val) {
        if (is_full()) {
            resize();
        }

        data_[top_++] = val;
    }

    int pop() {
        if (is_empty()) {
            throw exception();
        }

        return data_[--top_];
    }

private:
    void resize() {
        cout << "Resizing!" << endl;
        int *temp = data_;
        data_ = new int[size_ + chunk_];

        for (int i = 0; i < size_; i++) {
            data_[i] = temp[i];
        }

        delete [] temp;
        size_ += chunk_;

        cout << "Resized!" << endl;
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    try {
        cout << st.pop() << endl;
        cout << st.pop() << endl;
        cout << st.pop() << endl;
    } catch (const exception &e) {
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}
