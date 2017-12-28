#ifndef MANIPULATING_HH_
#define MANIPULATING_HH_

#include "operation.hh"

class ManipulatingOperation : public Operation {
public:
    ManipulatingOperation(Calculator& calculator, const std::string& name);

    void eval();

protected:
    virtual void execute() = 0;
};

#endif /* end of include guard: MANIPULATING_HH_ */
