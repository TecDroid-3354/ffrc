#pragma once
#include <utility>

#include "encoders/builders/MotorEncoderBuilder.hh"
#include "encoders/devices/REV/SparkMaxRelativeEncoder.hh"
#include "motorcontrollers/devices/REV/CANSparkMax.hh"

namespace ffrc {

    namespace builders {

        namespace encoders {

            class SparkMaxRelativeEncoder: MotorEncoderBuilder<devices::encoders::SparkMaxRelativeEncoder> {
                public:
                    SparkMaxRelativeEncoder(std::shared_ptr<devices::motorcontrollers::MotorController>);

                    SparkMaxRelativeEncoder* SetResolution(long double)          override;
                    SparkMaxRelativeEncoder* SetPositionConversionFactor(double) override;
                    SparkMaxRelativeEncoder* StartWithDistance(double)           override;

                    std::shared_ptr<devices::encoders::SparkMaxRelativeEncoder> Build();

                protected:
                    std::shared_ptr<devices::motorcontrollers::CANSparkMax> from;

            };

        }

    }

}