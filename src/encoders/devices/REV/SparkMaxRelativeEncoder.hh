#pragma once

#include "encoders/devices/MotorEncoder.hh"

#include <rev/SparkMaxRelativeEncoder.h>

namespace ffrc {
    
    namespace encoders {

        namespace devices {

            class SparkMaxRelativeEncoder: public MotorEncoder {
                public:
                    SparkMaxRelativeEncoder(std::unique_ptr<rev::SparkMaxRelativeEncoder>);

                    void     SetResolution(uint32_t)             override;
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
                    std::unique_ptr<rev::SparkMaxRelativeEncoder> encoder;

            };

        }

    }

}