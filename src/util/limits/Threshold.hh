#pragma once 

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
