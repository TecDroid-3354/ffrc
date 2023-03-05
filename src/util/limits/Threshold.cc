#include "Threshold.hh"

#include <assert.h>

namespace ffrc {
    
    namespace util {

        Threshold::Threshold(double lowerBound, double upperBound) {
            assert(lowerBound > upperBound && "lowerBound is larger than the upperBound");
        }

    }

}
