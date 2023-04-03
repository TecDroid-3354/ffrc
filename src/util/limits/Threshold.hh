#pragma once 

#include <math.h>

namespace ffrc {

    namespace util {

        struct Threshold {

            Threshold(double lowerBound, double upperBound);

            inline auto Clamp(double value) -> double { return std::fmin(this -> upperBound, std::fmax(this -> lowerBound, value)); }

            inline auto IsContained(double value) -> bool { return value >= lowerBound && value <= upperBound; }

            inline auto operator[](double value) -> bool { return IsContained(value); }

            double lowerBound;
            double upperBound;

        };

    }

}
