#include "SparkMaxRelativeEncoder.hh"

#include <memory>
#include <assert.h>

namespace ffrc {

    namespace builders {

        namespace encoders  {

            SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(std::shared_ptr<devices::motorcontrollers::MotorController> from) {
                // TODO: REQUIRES TESTING!!!
                std::shared_ptr<devices::motorcontrollers::CANSparkMax> sparkMaxController = std::static_pointer_cast<devices::motorcontrollers::CANSparkMax>(from);

                assert(sparkMaxController.get() != nullptr &&
                    "The MotorController passed in must be a Shared Pointer to a ffrc::devices::motorcontrollers::CANSparkMax."
                );

                this -> from = sparkMaxController;

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

            std::shared_ptr<devices::encoders::SparkMaxRelativeEncoder> SparkMaxRelativeEncoder::Build() {
                std::shared_ptr<rev::SparkMaxRelativeEncoder> encoder = from -> GetOrCreateEncoder();

                encoder -> SetPositionConversionFactor(positionConversionFactor);
                encoder -> SetPosition(startingDistance);
                // Resolution unneeded: 42

                std::shared_ptr<devices::encoders::SparkMaxRelativeEncoder> relativeEncoder =
                    std::make_shared<devices::encoders::SparkMaxRelativeEncoder>(std::move(encoder));

                return relativeEncoder;
            }

        }

    }

}