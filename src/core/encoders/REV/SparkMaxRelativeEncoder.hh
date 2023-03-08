#pragma once

#include "core/encoders/MotorEncoder.hh"

#include <rev/SparkMaxRelativeEncoder.h>

namespace ffrc {

    namespace encoders {

        class SparkMaxRelativeEncoder: public MotorEncoder {
            public:
                SparkMaxRelativeEncoder(std::unique_ptr<rev::SparkMaxRelativeEncoder>);

                void SetDistancePerPulse(double);
                void SetMinRate(double);
                void SetSamplesToAverage(int);
                void Invert();

                bool IsLastMovementForward();
                bool IsStopped();

                void Reset();

                int GetCount();
                double GetDistance();
                double GetDistancePerPulse();
                double GetRate();
                int GetEncodingScale();
                int GetFPGAIndex();
                int GetRawValue();

                units::time::second_t GetLastPulsePeriod();

            private:
                std::unique_ptr<rev::SparkMaxRelativeEncoder> encoder;
                double lastPosition = 0.0;
        };

    }

}
