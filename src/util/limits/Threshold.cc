#include "Threshold.hh"

#include <assert.h>
#include <math.h>

namespace ffrc {
    
    namespace util {

        Threshold::Threshold(double lowerBound, double upperBound):
        lowerBound(lowerBound), upperBound(upperBound) {
            assert(lowerBound < upperBound && "lowerBound is greater than the upperBound");
        }
        
        double ClampValueInThreshold(Threshold& threshold, double value) {
            return std::fmin(threshold.upperBound, std::fmax(threshold.lowerBound, value));
        }

    }

}
