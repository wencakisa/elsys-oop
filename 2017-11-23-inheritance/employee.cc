#include <iostream>

using namespace std;

class Employee {
    string name_;
    long id_;
public:
    Employee(string name, long id)
    : name_(name), id_(id)
    {}

    const string& get_name() const {
        return name_;
    }

    long get_id() const {
        return id_;
    }

    void print() const {
        cout << "Emp:\t" << name_ << "\t" << id_ << endl;
    }
};

class Manager : public Employee {
    int level_;
public:
    Manager(string name, long id, int level)
    : Employee(name, id), level_(level)
    {}

    int get_level() const {
        return level_;
    }

    void print() const {
        cout << "Mng:\t" << get_name() << "\t" << get_id() << "\t" << level_ << endl;
    }
};

int main() {
    Employee e("Ivan", 1);
    e.print();

    Manager m("Gosho", 2, 3);
    m.print();
    
    return 0;
}
