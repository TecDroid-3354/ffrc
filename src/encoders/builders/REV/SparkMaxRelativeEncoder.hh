#pragma once
#include <utility>

#include "encoders/builders/MotorEncoderBuilder.hh"
#include "encoders/devices/REV/SparkMaxRelativeEncoder.hh"
#include "motorcontrollers/controllers/REV/CANSparkMax.hh"

namespace ffrc {

    namespace encoders {

        namespace builders {

            class SparkMaxRelativeEncoder: MotorEncoderBuilder<devices::SparkMaxRelativeEncoder> {
                public:
                    SparkMaxRelativeEncoder(std::shared_ptr<motorcontrollers::devices::CANSparkMax>);

                    SparkMaxRelativeEncoder* SetResolution(uint32_t)             override;
                    SparkMaxRelativeEncoder* SetPositionConversionFactor(double) override;
                    SparkMaxRelativeEncoder* StartWithDistance(double)           override;

                    std::shared_ptr<devices::SparkMaxRelativeEncoder> Build();

                protected:
                    std::shared_ptr<motorcontrollers::devices::CANSparkMax> from;

            };

        }

    }

}