#ifndef SWAP_HH_
#define SWAP_HH_

#include "manipulating.hh"

class Swap : public ManipulatingOperation {
public:
    Swap(Calculator& calculator);

    void execute();
};

#endif /* end of include guard: SWAP_HH_ */
