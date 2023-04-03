#include "Threshold.hh"

#include <assert.h>

namespace ffrc {
    
    namespace util {

        Threshold::Threshold(double lowerBound, double upperBound):
        lowerBound(lowerBound), upperBound(upperBound) {
            assert(lowerBound < upperBound && "lowerBound is greater than the upperBound");
        }

    }

}
