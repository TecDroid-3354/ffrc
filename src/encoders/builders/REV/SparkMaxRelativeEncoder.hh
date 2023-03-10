#pragma once

#include "encoders/builders/MotorEncoderBuilder.hh"
#include "encoders/devices/REV/SparkMaxRelativeEncoder.hh"

namespace ffrc {

    namespace encoders {

        namespace builders {

            class SparkMaxRelativeEncoder: MotorEncoderBuilder<devices::SparkMaxRelativeEncoder> {
                public:
                    SparkMaxRelativeEncoder(rev::SparkMaxRelativeEncoder&&);

                    SparkMaxRelativeEncoder* SetResolution(uint32_t)             override;
                    SparkMaxRelativeEncoder* SetPositionConversionFactor(double) override;
                    SparkMaxRelativeEncoder* StartWithDistance(double)           override;

                    std::shared_ptr<devices::SparkMaxRelativeEncoder> Build() override;

                protected:
                    std::unique_ptr<rev::SparkMaxRelativeEncoder> from;

            };

        }

    }

}