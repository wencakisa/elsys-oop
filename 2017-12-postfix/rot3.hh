#ifndef ROT3_HH
#define ROT3_HH

#include "manipulating.hh"

class Rot3 : public ManipulatingOperation {
public:
    Rot3(Calculator& calculator);

    void execute();
};

#endif /* end of include guard: ROT_3_HH */
