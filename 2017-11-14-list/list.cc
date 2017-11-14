#include <iostream>

using namespace std;

class ListError {
    string msg_;
public:
    ListError(string message) : msg_(message) {}

    string get_msg() const {
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

    class iterator {
        friend class List;

        List *list_;
        Node *current_;

        iterator(List *list, Node *current) : list_(list), current_(current) {}

    public:
        // Pre-increment
        iterator& operator++() {
            current_ = current_->next_;
            return *this;
        }

        bool operator==(const iterator& other) {
            return list_ == other.list_ && current_ == other.current_;
        }

        bool operator!=(const iterator& other) {
            return !operator==(other);
        }

        // *iterator
        int& operator*() {
            return current_->data_;
        }
    };

    iterator begin() {
        return iterator(this, head_->next_);
    }

    iterator end() {
        return iterator(this, head_);
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

    cout << ll.empty() << endl;

    try {
        ll.push_back(1);
        ll.push_back(2);
        ll.push_back(3);
        cout << "Back: " << ll.back() << " / Front: " << ll.front() << endl;
        ll.push_front(0);
        cout << "Back: " << ll.back() << " / Front: " << ll.front() << endl;

        for (auto it = ll.begin(); it != ll.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        ll.pop_back();
        ll.pop_back();
        cout << "Back: " << ll.back() << " / Front: " << ll.front() << endl;

        for (auto it = ll.begin(); it != ll.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

    } catch (const ListError& ex) {
        cout << ex.get_msg() << endl;
    }

    return 0;
}
