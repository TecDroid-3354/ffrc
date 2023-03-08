#pragma once

#include <frc/Encoder.h>

#include "encoders/MotorEncoder.hh"

namespace ffrc {

    namespace encoders {

        class GenericEncoder: public MotorEncoder {
            public:
                GenericEncoder(std::unique_ptr<frc::Encoder>, unsigned int);

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
                std::unique_ptr<frc::Encoder> encoder;
        };

    }

}