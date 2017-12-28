#ifndef OPERATION_HH_
#define OPERATION_HH_

#include <string>

#include "calculator.hh"

class Operation {
protected:
    Calculator& calculator_;
private:
    std::string name_;
public:
    Operation(Calculator& calculator, const std::string& name)
    : calculator_(calculator), name_(name)
    {}

    const std::string& get_name() const {
        return name_;
    }

    virtual void eval() = 0;
};

#endif
