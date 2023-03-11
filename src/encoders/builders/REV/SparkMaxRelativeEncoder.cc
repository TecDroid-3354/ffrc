#include "SparkMaxRelativeEncoder.hh"

#include <memory>

namespace ffrc {

    namespace encoders {

        namespace builders {

            SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(std::shared_ptr<motorcontrollers::devices::MotorController> from) {
                static_assert(std::is_same<Type, devices::SparkMaxRelativeEncoder>::value,
                    "The MotorController passed in must be a SparkMax."
                );

                this -> from = std::static_pointer_cast<motorcontrollers::devices::CANSparkMax>(from);
            }

            SparkMaxRelativeEncoder* SparkMaxRelativeEncoder::SetResolution(uint32_t resolution) {
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

            std::shared_ptr<devices::SparkMaxRelativeEncoder> SparkMaxRelativeEncoder::Build() {
                std::shared_ptr<rev::SparkMaxRelativeEncoder> encoder = from -> GetOrCreateEncoder();

                encoder -> SetPositionConversionFactor(positionConversionFactor);
                encoder -> SetPosition(startingDistance);
                // Resolution unneeded: 42

                std::shared_ptr<devices::SparkMaxRelativeEncoder> relativeEncoder =
                    std::make_shared<devices::SparkMaxRelativeEncoder>(std::move(encoder));

                return relativeEncoder;
            }

        }

    }

}