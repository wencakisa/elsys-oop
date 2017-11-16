#include <iostream>

using namespace std;

class ListError {
    const string msg_;
public:
    ListError(const string message) : msg_(message) {}

    const string get_msg() const {
        return msg_;
    }
};

class List {
    struct Node {
        int data_;
        Node *prev_;
        Node *next_;

        Node(int val) : data_(val), prev_(nullptr), next_(nullptr) {}
    };

    class abstract_iterator {
        friend class List;

        List *list_;
        Node *current_;

        abstract_iterator(List *list, Node *current) : list_(list), current_(current) {}

    public:
        bool operator==(const abstract_iterator& other) {
            return list_ == other.list_ && current_ == other.current_;
        }

        bool operator!=(const abstract_iterator& other) {
            return !operator==(other);
        }

        int& operator*() {
            return current_->data_;
        }
    };

    Node *head_;
public:
    List() : head_(new Node(0)) {
        head_->prev_ = head_->next_ = head_;
    }

    List(const List& other) : head_(other.head_) {
        head_->prev_ = other.head_->prev_;
        head_->next_ = other.head_->next_;
    }

    ~List() {
        while (!empty()) {
            pop_back();
        }

        delete head_;
    }

    List& operator=(const List& other) {
        if (this != &other) {
            delete head_;

            head_ = other.head_;
            head_->prev_ = other.head_->prev_;
            head_->next_ = other.head_->next_;
        }

        return *this;
    }

    class iterator : public abstract_iterator {
        friend class List;

        iterator(List *list, Node *current) : abstract_iterator(list, current) {}

    public:
        // Pre-increment
        iterator& operator++() {
            current_ = current_->next_;
            return *this;
        }

        // Post-increment
        iterator operator++(int) {
            iterator res(list_, current_);
            current_ = current_->next_;
            return res;
        }

        iterator& operator--() {
            current_ = current_->prev_;
            return *this;
        }
    };

    class reverse_iterator : public abstract_iterator {
        friend class List;

        reverse_iterator(List *list, Node *current) : abstract_iterator(list, current) {}

    public:
        reverse_iterator& operator++() {
            current_ = current_->prev_;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator res(list_, current_);
            current_ = current_->prev_;
            return res;
        }

        reverse_iterator& operator--() {
            current_ = current_->next_;
            return *this;
        }
    };

    class const_iterator : public abstract_iterator {
        friend class List;

        const_iterator(List *list, Node *current) : abstract_iterator(list, current) {}
    public:
        // TODO: Implement
    };

    iterator begin() {
        return iterator(this, head_->next_);
    }

    iterator end() {
        return iterator(this, head_);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(this, head_->prev_);
    }

    reverse_iterator rend() {
        return reverse_iterator(this, head_);
    }

    iterator insert(iterator pos, int val) {
        Node *current = pos.current_;
        Node *prev = current->prev_;
        Node *ptr = new Node(val);

        current->prev_ = ptr;
        ptr->prev_ = prev;

        prev->next_ = ptr;
        ptr->next_ = current;

        return iterator(this, ptr);
    }

    iterator erase(iterator pos) {
        if (empty()) {
            throw ListError("List is empty.");
        }

        Node *current = pos.current_;
        Node *prev = current->prev_;
        Node *next = current->next_;

        prev->next_ = next;
        next->prev_ = prev;

        delete current;

        return iterator(this, next);
    }

    bool empty() const {
        return head_->next_ == head_;
    }

    int back() const {
        if (empty()) {
            throw ListError("List is empty.");
        }

        return head_->prev_->data_;
    }

    int front() const {
        if (empty()) {
            throw ListError("List is empty.");
        }

        return head_->next_->data_;
    }

    void push_back(int val) {
        Node *ptr = new Node(val);
        Node *back = head_->prev_;

        back->next_ = ptr;
        ptr->next_ = head_;

        head_->prev_ = ptr;
        ptr->prev_ = back;
    }

    void push_front(int val) {
        Node *ptr = new Node(val);
        Node *front = head_->next_;

        front->prev_ = ptr;
        ptr->prev_ = head_;

        head_->next_ = ptr;
        ptr->next_ = front;
    }

    void pop_back() {
        if (empty()) {
            throw ListError("List is empty.");
        }

        Node *back = head_->prev_;
        Node *new_back = back->prev_;

        new_back->next_ = head_;
        head_->prev_ = new_back;

        delete back;
    }

    void pop_front() {
        if (empty()) {
            throw ListError("List is empty.");
        }

        Node *front = head_->next_;
        Node *new_front = front->next_;

        head_->next_ = new_front;
        new_front->prev_ = head_;

        delete front;
    }
};

int main() {
    List ll;

    try {
        ll.push_back(1);
        ll.push_back(2);
        ll.push_back(3);
        ll.push_front(0);

        cout << "Default list: " << endl;
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        cout << "Inserting with iterators: " << endl;
        List::iterator begin = ll.begin();
        ll.insert(begin, -1);
        begin++; begin++;
        ll.insert(begin, 4);

        for (auto it = ll.begin(); it != ll.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        cout << "Popping back 2 times and 1 time front: " << endl;
        ll.pop_back();
        ll.pop_back();
        ll.pop_front();

        for (auto it = ll.begin(); it != ll.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        cout << "Reversed list: " << endl;
        for (List::reverse_iterator rit = ll.rbegin(); rit != ll.rend(); rit++) {
            cout << *rit << " ";
        }
        cout << endl;

    } catch (const ListError& ex) {
        cout << ex.get_msg() << endl;
    }

    return 0;
}
