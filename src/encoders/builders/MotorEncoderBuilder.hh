#pragma once

#include <stdint.h>
#include <memory>

namespace ffrc {

    namespace builders {

        namespace encoders {

            template <typename EncoderType>
            class MotorEncoderBuilder {
                public:
                    virtual MotorEncoderBuilder* SetResolution(long double)          = 0;
                    virtual MotorEncoderBuilder* SetPositionConversionFactor(double) = 0;
                    virtual MotorEncoderBuilder* StartWithDistance(double)           = 0;

                    using Type = EncoderType;

                protected:
                    uint32_t resolution = 2048;
                    double positionConversionFactor = 1.0;
                    double startingDistance = 0.0;

            };

        }

    }

}