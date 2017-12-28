#ifndef DUP_HH_
#define DUP_HH_

#include "manipulating.hh"

class Dup : public ManipulatingOperation {
public:
    Dup(Calculator& calculator);

    void execute();
};

#endif /* end of include guard: DUP_HH_ */
