#pragma once

#include "encoders/devices/MotorEncoder.hh"

#include <frc/Encoder.h>

namespace ffrc {

    namespace devices {

        namespace encoders {

            class AMT103: public MotorEncoder {
                public:
                    AMT103(std::unique_ptr<frc::Encoder>);

                    void     SetResolution(long double)          override;
                    double   GetResolution()                     override;

                    void     SetPositionConversionFactor(double) override;
                    double   GetPositionConversionFactor()       override;

                    void     SetTraveledDistance(double)         override;
                    double   GetTraveledDistance()               override;

                    double   GetVelocity()                       override;

                    bool     IsStopped()                         override;

                    void     SetMeasurementPeriod(uint32_t)      override;
                    uint32_t GetMeasurementPeriod()              override;

                    void     SetSamplesToAverage(int)            override;
                    int      GetSamplesToAverage()               override;

                    void     Reset()                             override;
                
                private:
                    std::unique_ptr<frc::Encoder> encoder;
                    double fakeTraveledDistance = 0;

            };

        }

    }

}
