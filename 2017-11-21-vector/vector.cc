#include <iostream>
#include <cstdlib>

using namespace std;

class VectorError {
    const string msg_;
public:
    VectorError(const string msg) : msg_(msg) {}

    const string get_msg() const {
        return msg_;
    }
};

class Vector {
    int capacity_;
    int size_;
    int *buffer_;
    const static int RESIZE_MUL_ = 2;

    class abstract_iterator {
        friend class Vector;

        Vector* vector_;
        int current_index_;
    public:
        abstract_iterator(Vector* v, int current) :
            vector_(v),
            current_index_(current)
        {}

        bool operator==(const abstract_iterator& other) {
            return (vector_ == other.vector_) && (current_index_ == other.current_index_);
        }

        bool operator!=(const abstract_iterator& other) {
            return !operator==(other);
        }

        int& operator*() {
            return (*vector_)[current_index_];
        }
    };

public:
    const static int DEF_CAP = 10;

    Vector(int capacity=DEF_CAP) :
        capacity_(capacity),
        size_(0),
        buffer_(new int[capacity])
    {}

    Vector(const Vector& other) :
        capacity_(other.capacity_),
        size_(other.size_),
        buffer_(new int[other.size_])
    {
        for (int i = 0; i < size_; ++i) {
            buffer_[i] = other.buffer_[i];
        }
    }

    ~Vector() {
        delete [] buffer_;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete [] buffer_;

            capacity_ = other.capacity_;
            size_ = other.size_;
            buffer_ = new int[size_];

            for (int i = 0; i < size_; i++) {
                buffer_[i] = other.buffer_[i];
            }
        }

        return *this;
    }

    class iterator : public abstract_iterator {
        friend class Vector;

        iterator(Vector* v, int current) :
            abstract_iterator(v, current)
        {}
    public:
        iterator& operator++() {
            current_index_++;
            return *this;
        }

        iterator operator++(int) {
            iterator res(vector_, current_index_++);
            return res;
        }
    };

    iterator begin() {
        return iterator(this, 0);
    }

    iterator end() {
        return iterator(this, size_);
    }

    iterator insert(iterator pos, const int& x) {
        int index = pos.current_index_;
        int *buffer = pos.vector_->buffer_;
        int *tmp = new int[size_ + 1];

        int i = 0;
        for (; i < index; ++i) {
            tmp[i] = buffer[i];
        }
        tmp[i++] = x;
        size_++;
        for (; i < size_; ++i) {
            tmp[i] = buffer[i - 1];
        }

        buffer_ = tmp;

        return iterator(this, index);
    }

    iterator erase(iterator pos) {
        int index = pos.current_index_;
        int *buffer = pos.vector_->buffer_;
        int *tmp = new int[size_ + 1];

        int i = 0;
        for (; i < index; ++i) {
            tmp[i] = buffer[i];
        }
        size_--;
        for (; i < size_; ++i) {
            tmp[i] = buffer[i + 1];
        }

        buffer_ = tmp;

        return iterator(this, index);
    }

    iterator erase(iterator first, iterator last) {
        while (first != last) {
            erase(first);
            first++;
        }

        return erase(last);
    }

    class reverse_iterator : public abstract_iterator {
        friend class Vector;

        reverse_iterator(Vector* v, int current) :
            abstract_iterator(v, current)
        {}
    public:
        reverse_iterator& operator++() {
            current_index_--;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator res(vector_, --current_index_);
            return res;
        }
    };

    reverse_iterator rbegin() {
        return reverse_iterator(this, size_ - 1);
    }

    reverse_iterator rend() {
        return reverse_iterator(this, -1);
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    bool full() const {
        return size_ == capacity_;
    }

    int& operator[](int n) {
        if (n > size_) {
            throw VectorError("Index out of bounds.");
        }

        return buffer_[n];
    }

    const int& operator[](int n) const {
        return operator[](n);
    }

    int& front() {
        return operator[](0);
    }

    const int& front() const {
        return front();
    }

    int& back() {
        return operator[](size_ - 1);
    }

    const int& back() const {
        return back();
    }

    void clear() {
        size_ = 0;
    }

    void push_back(const int& value) {
        if (full()) {
            resize();
        }

        buffer_[size_++] = value;
    }

    void pop_back() {
        if (empty()) {
            throw VectorError("Vector is empty.");
        }

        --size_;
    }

private:
    void resize() {
        int *tmp = buffer_;

        capacity_ *= RESIZE_MUL_;
        buffer_ = new int[capacity_];

        for (int i = 0; i < size_; i++) {
            buffer_[i] = tmp[i];
        }

        delete [] tmp;
    }
};

ostream& operator<<(ostream& out, Vector& v) {
    out << "{";
    for (Vector::iterator it = v.begin(); it != v.end(); ++it) {
        out << *it << ",";
    }
    out << "}";

    return out;
}

void fill(Vector& v, int from, int to) {
    for (int i = from; i < to; ++i) {
        v.push_back(i);
    }
}

int main(int argc, const char* argv[]) {
    int v1_start = atoi(argv[1]);
    int v1_end = atoi(argv[2]);
    Vector v1;
    fill(v1, v1_start, v1_end);

    int v2_start = atoi(argv[3]);
    int v2_end = atoi(argv[4]);
    Vector v2;
    fill(v2, v2_start, v2_end);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    v1.push_back(-100);
    v2.push_back(-100);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector v = v2;
    cout << "v: " << v << endl;

    for (Vector::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) {
        v.insert(v.begin(), *rit);
    }

    cout << "v: " << v << endl;

    return 0;
}
