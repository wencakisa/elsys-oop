#include <iostream>
#include <list>

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

    virtual void print() const {
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
    Employee e1("Ivan", 1);
    Employee e2("Pesho", 2);
    Manager m("Gosho", 3, 3);

    list<Employee*> employees;
    employees.push_back(&e1);
    employees.push_back(&e2);
    employees.push_back(&m);

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        (*it)->print();
    }
}
