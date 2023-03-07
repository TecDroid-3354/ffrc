#ifndef FFRC_THRESHOLD_HH
#define FFRC_THRESHOLD_HH

namespace ffrc {

    namespace util {

        struct Threshold {
            double lowerBound;
            double upperBound;

            Threshold(double lowerBound, double upperBound);

            inline auto operator[](float value) -> bool { return value >= lowerBound && value <= upperBound; }
        };

        double ClampValueInThreshold(Threshold&, double);

    }

}

#endif