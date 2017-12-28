#ifndef COMPOSITE_HH_
#define COMPOSITE_HH_

#include <list>

#include "operation.hh"

class CompositeOperation : public Operation {
    std::list<Operation*> children_;
public:
    CompositeOperation(Calculator& calculator, const std::string& name);

    void add_child(Operation* op);
    void eval();
};

#endif /* end of include guard: COMPOSITE_HH_ */
