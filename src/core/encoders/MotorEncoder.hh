#pragma once

#include <units/time.h>

namespace ffrc {

    namespace encoders {

        class MotorEncoder {
            public:
                MotorEncoder(unsigned int);

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

            protected:
                unsigned int resolution;
        };

    }

}
