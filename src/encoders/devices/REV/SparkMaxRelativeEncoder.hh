#pragma once

#include "encoders/devices/MotorEncoder.hh"

#include <rev/SparkMaxRelativeEncoder.h>

namespace ffrc {
    
    namespace encoders {

        namespace devices {

            class SparkMaxRelativeEncoder: public MotorEncoder {
                public:
                    SparkMaxRelativeEncoder(std::unique_ptr<rev::SparkMaxRelativeEncoder>);

                    virtual void     SetResolution(uint32_t)             = 0;
                    virtual double   GetResolution()                     = 0;

                    virtual void     SetPositionConversionFactor(double) = 0;
                    virtual double   GetPositionConversionFactor()       = 0;

                    virtual void     SetTraveledDistance(double)         = 0;
                    virtual double   GetTraveledDistance()               = 0;

                    virtual double   GetVelocity()                       = 0;

                    virtual bool     IsStopped()                         = 0;

                    virtual void     SetMeasurementPeriod(uint32_t)      = 0;
                    virtual uint32_t GetMeasurementPeriod()              = 0;

                    virtual void     SetSamplesToAverage(int)            = 0;
                    virtual int      GetSamplesToAverage()               = 0;

                    virtual void     Reset()                             = 0;

                private:
                    std::unique_ptr<rev::SparkMaxRelativeEncoder> encoder;

            };

        }

    }

}