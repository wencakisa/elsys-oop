#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

#define STOP_WORD "quit"
#define ELEMENTS_DELIMITER ';'
#define COMMANDS_DELIMITER '.'
#define OPERATION_DELIMITER ':'

vector<string> split_into_tokens(const string& str, const char& delimiter) {
    istringstream in(str);

    vector<string> tokens;
    string chunk;
    while (getline(in, chunk, delimiter)) {
        tokens.push_back(chunk);
    }

    return tokens;
}

template <class T>
void print_array(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int to_int(const string& str) {
    istringstream iss(str);
    int value;
    iss >> value;

    return value;
}

class ListOfArrays {
    struct ArrayNode {
        int* data_;
        int size_;
        ArrayNode* prev_;
        ArrayNode* next_;

        ArrayNode(int* data, int size)
        : data_(data), size_(size), prev_(nullptr), next_(nullptr)
        {}

        ~ArrayNode() {
            delete [] data_;
        }
    };

    int size_;
    ArrayNode* head_;
public:
    class Iterator {
        friend class ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;
    public:
        Iterator(ListOfArrays& list, ArrayNode* current)
        : list_(list), current_(current)
        {}

        bool operator==(const Iterator& other) {
            return (list_.head_ == other.list_.head_) && (current_ == other.current_);
        }

        bool operator!=(const Iterator& other) {
            return !operator==(other);
        }

        Iterator& operator++() {
            current_ = current_->next_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator res(list_, current_);
            current_ = current_->next_;
            return res;
        }

        int& operator[](const int& index) {
            return current_->data_[index];
        }

        Iterator& operator*=(const int& coef) {
            for (int i = 0; i < size(); ++i) {
                operator[](i) *= coef;
            }

            return *this;
        }

        Iterator& operator+=(const int& value) {
            for (int i = 0; i < size(); ++i) {
                operator[](i) += value;
            }

            return *this;
        }

        Iterator& ordered(bool ascending = true) {
            if (ascending) {
                sort(current_->data_, current_->data_ + size(), less<int>());
            } else {
                sort(current_->data_, current_->data_ + size(), greater<int>());
            }

            return *this;
        }

        int size() const {
            return current_->size_;
        }

        void show() {
            for (int i = 0; i < size(); ++i) {
                cout << operator[](i);

                if (i < size() - 1) {
                    cout << " ";
                }
            }
        }

        int sum() {
            int result = 0;

            for (int i = 0; i < size(); ++i) {
                result += operator[](i);
            }

            return result;
        }

        double average() {
            return static_cast<double>(sum()) / size();
        }

        double median() {
            this->ordered();
            int middle = size() / 2.0;

            if (size() % 2 == 0) {
                return (operator[](middle) + operator[](middle - 1)) / 2.0;
            } else {
                return operator[](middle);
            }
        }
    };

    ListOfArrays()
    : size_(0), head_(new ArrayNode(0, 0))
    {
        head_->prev_ = head_->next_ = head_;
    }

    ListOfArrays(const ListOfArrays& other)
    : size_(0), head_(new ArrayNode(0, 0)) {
        head_->prev_ = head_->next_ = head_;

        ArrayNode *current = other.head_->next_;
        for (int i = 0; i < other.size_; ++i) {
            int *new_data = new int[current->size_];
            for (int j = 0; j < current->size_; ++j) {
                new_data[j] = current->data_[j];
            }

            push(new_data, 0, current->size_);
            current = current->next_;
        }
    }

    ListOfArrays& operator=(const ListOfArrays& other) {
        if (this != &other) {
            delete head_;

            size_ = 0;
            head_ = new ArrayNode(0, 0);
            head_->prev_ = head_->next_ = head_;

            ArrayNode *current = other.head_->next_;
            for (int i = 0; i < other.size_; ++i) {
                int *new_data = new int[current->size_];
                for (int j = 0; j < current->size_; ++j) {
                    new_data[j] = current->data_[j];
                }

                push(new_data, 0, current->size_);
                current = current->next_;
            }
        }

        return *this;
    }

    int size() const {
        return size_;
    }

    void push(int array[], int position, int length) {
        ArrayNode *ptr = new ArrayNode(array + position, length - position);
        ArrayNode *back = head_->prev_;

        back->next_ = ptr;
        ptr->next_ = head_;

        head_->prev_ = ptr;
        ptr->prev_ = back;

        size_++;
    }

    void averages(double averages[]) {
        int index = 0;
        for (auto it = begin(); it != end(); ++it) {
            averages[index++] = it.average();
        }
    }

    void medians(double medians[]) {
        int index = 0;
        for (auto it = begin(); it != end(); ++it) {
            medians[index++] = it.median();
        }
    }

    void sizes(int sizes[]) {
        int index = 0;
        for (auto it = begin(); it != end(); ++it) {
            sizes[index++] = it.size();
        }
    }

    void sums(int sums[]) {
        int index = 0;
        for (auto it = begin(); it != end(); ++it) {
            sums[index++] = it.sum();
        }
    }

    Iterator begin() {
        return Iterator(*this, head_->next_);
    }

    Iterator end() {
        return Iterator(*this, head_);
    }

    ListOfArrays& ordered(bool ascending = true) {
        for (auto it = begin(); it != end(); ++it) {
            it.ordered(ascending);
        }

        return *this;
    }

    ListOfArrays& operator*=(const int& coef) {
        for (auto it = begin(); it != end(); ++it) {
            it *= coef;
        }

        return *this;
    }

    ListOfArrays& operator+=(const int& value) {
        for (auto it = begin(); it != end(); ++it) {
            it += value;
        }

        return *this;
    }

    void show() {
        for (auto it = begin(); it != end(); ++it) {
            it.show();

            if (it.current_ != head_->prev_) {
                cout << ELEMENTS_DELIMITER << " ";
            }
        }

        cout << endl;
    }
};

istream& operator>>(istream& in, ListOfArrays& list) {
    string token;
    getline(cin, token);

    vector<string> tokens = split_into_tokens(token, ELEMENTS_DELIMITER);
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        istringstream token_stream(*it);

        const size_t size = (*it).size();
        int* arr = new int[size];
        int i = 0;

        int value;
        while (token_stream >> value) {
            arr[i++] = value;
        }

        list.push(arr, 0, i);
    }

    return in;
}

int main() {
    ListOfArrays l;
    cout << "> ";
    cin >> l;

    string token;
    while (true) {
        cout << "> ";
        getline(cin, token);

        if (token == STOP_WORD) {
            break;
        }

        vector<string> operations = split_into_tokens(token, COMMANDS_DELIMITER);
        bool use_iterator = operations.front() == "begin";

        ListOfArrays copy_list;
        copy_list = l;
        ListOfArrays::Iterator begin = copy_list.begin();

        for (auto it = operations.begin(); it != operations.end(); ++it) {
            vector<string> parts = split_into_tokens(*it, OPERATION_DELIMITER);

            string operation = parts.front();

            bool sort_ascending = true;
            if (operation == "ordered") {
                if (parts.size() > 1) {
                    sort_ascending = parts[1] == "true";
                }
            }

            if (use_iterator) {
                if (operation == "next") {
                    if (++begin == copy_list.end()) {
                        cout << "ERROR: End of iteration" << endl;
                        break;
                    }
                } else if (operation == "show") {
                    begin.show();
                    cout << endl;
                } else if (operation == "at") {
                    int index = to_int(parts.at(1));

                    if (index < l.size()) {
                        cout << begin[index] << endl;
                    } else {
                        cout << "ERROR: Index out of bounds" << endl;
                    }
                } else if (operation == "size") {
                    cout << begin.size() << endl;
                } else if (operation == "average") {
                    cout << begin.average() << endl;
                } else if (operation == "median") {
                    cout << begin.average() << endl;
                } else if (operation == "sum") {
                    cout << begin.sum() << endl;
                } else if (operation == "ordered") {
                    begin.ordered(sort_ascending);
                } else if (operation != "begin") {
                    cout << "ERROR: Unknown operation" << endl;
                    break;
                }
            } else {
                if (operation == "show") {
                    copy_list.show();
                } else if (operation == "size") {
                    cout << copy_list.size() << endl;
                } else if (operation == "sizes") {
                    int* sizes = new int[copy_list.size()];
                    copy_list.sizes(sizes);

                    print_array(sizes, copy_list.size());

                    delete [] sizes;
                } else if (operation == "averages") {
                    double* averages = new double[copy_list.size()];
                    copy_list.averages(averages);

                    print_array(averages, copy_list.size());

                    delete [] averages;
                } else if (operation == "medians") {
                    double* medians = new double[copy_list.size()];
                    copy_list.medians(medians);

                    print_array(medians, copy_list.size());

                    delete [] medians;
                } else if (operation == "sums") {
                    int* sums = new int[copy_list.size()];
                    copy_list.sums(sums);

                    print_array(sums, copy_list.size());

                    delete [] sums;
                } else if (operation == "mul") {
                    copy_list *= to_int(parts.at(1));
                } else if (operation == "add") {
                    copy_list += to_int(parts.at(1));
                } else if (operation == "ordered") {
                    copy_list.ordered(sort_ascending);
                } else {
                    cout << "ERROR: Unknown operation" << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
