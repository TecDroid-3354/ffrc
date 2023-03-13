#include "SparkMaxRelativeEncoder.hh"

#include <memory>
#include <assert.h>

namespace ffrc {

    namespace builders {

        namespace encoders  {

            SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(devices::motorcontrollers::MotorController& from):
            from(static_cast<devices::motorcontrollers::CANSparkMax&>(from)) {

                static_assert(std::is_same<devices::motorcontrollers::MotorController&, decltype(from)>::value,
                    "The MotorController passed in must be a Shared Pointer to a ffrc::devices::motorcontrollers::CANSparkMax."
                );

            }

            SparkMaxRelativeEncoder* SparkMaxRelativeEncoder::SetResolution(long double resolution) {
                this -> resolution = resolution;
                return this;
            }

            SparkMaxRelativeEncoder* SparkMaxRelativeEncoder::SetPositionConversionFactor(double factor) {
                this -> positionConversionFactor = factor;
                return this;
            }

            SparkMaxRelativeEncoder* SparkMaxRelativeEncoder::StartWithDistance(double distance) {
                this -> startingDistance = distance;
                return this;
            }

            devices::encoders::SparkMaxRelativeEncoder SparkMaxRelativeEncoder::Build() {
                std::shared_ptr<rev::SparkMaxRelativeEncoder> encoder = from.GetOrCreateEncoder();

                encoder -> SetPositionConversionFactor(positionConversionFactor);
                encoder -> SetPosition(startingDistance);
                // Resolution unneeded: 42

                devices::encoders::SparkMaxRelativeEncoder relativeEncoder{std::move(encoder)};

                return relativeEncoder;
            }

        }

    }

}