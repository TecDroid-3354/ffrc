#include "SparkMaxRelativeEncoder.hh"

#include <memory>

namespace ffrc {

    namespace encoders {

        namespace builders {

            SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(rev::SparkMaxRelativeEncoder&& from):
            from(std::unique_ptr<rev::SparkMaxRelativeEncoder>(new rev::SparkMaxRelativeEncoder(from))) {}

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
                from -> SetPositionConversionFactor(positionConversionFactor);
                from -> SetPosition(startingDistance);
                // Resolution unneeded: 42

                std::shared_ptr<devices::SparkMaxRelativeEncoder> relativeEncoder = std::make_unique<devices::SparkMaxRelativeEncoder>(std::move(from));

                return relativeEncoder;
            }

        }

    }

}