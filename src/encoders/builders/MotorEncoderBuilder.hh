#pragma once

#include <stdint.h>
#include <memory>

namespace ffrc {

    namespace encoders {

        namespace builders {

            template <typename EncoderType>
            class MotorEncoderBuilder {
                public:
                    virtual MotorEncoderBuilder* SetResolution(uint32_t)             = 0;
                    virtual MotorEncoderBuilder* SetPositionConversionFactor(double) = 0;
                    virtual MotorEncoderBuilder* StartWithDistance(double)           = 0;

                    virtual std::shared_ptr<EncoderType> Build() = 0;
                
                protected:
                    uint32_t resolution = 2048;
                    double positionConversionFactor = 1.0;
                    double startingDistance = 0.0;

            };

        }

    }

}