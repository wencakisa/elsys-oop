#ifndef DROP_HH_
#define DROP_HH_

#include "manipulating.hh"

class Drop : public ManipulatingOperation {
public:
    Drop(Calculator& calculator);

    void execute();
};

#endif /* end of include guard: DROP_HH_ */
