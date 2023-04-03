#include "SparkMaxRelativeEncoder.hh"

namespace ffrc {
    
    namespace devices {

        namespace encoders {

            SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(std::shared_ptr<rev::SparkMaxRelativeEncoder> encoder):
            encoder(encoder) {}

            void SparkMaxRelativeEncoder::SetResolution(long double distance) {
                // Already Handled by the encoder
                throw std::runtime_error("Cannot set the resolution of a SparkMaxRelativeEncoder");
            }

            double SparkMaxRelativeEncoder::GetResolution() {
                return encoder -> GetCountsPerRevolution();
			}

            void SparkMaxRelativeEncoder::SetPositionConversionFactor(double factor) {
                this -> positionConversionFactor = factor;
                encoder -> SetPositionConversionFactor(positionConversionFactor);
            }

            double SparkMaxRelativeEncoder::GetPositionConversionFactor() {
                return encoder -> GetPositionConversionFactor();
            }

            void SparkMaxRelativeEncoder::SetTraveledDistance(double) {
                this -> encoder -> SetPosition(0);
			}

            double SparkMaxRelativeEncoder::GetTraveledDistance() {
                return encoder -> GetPosition();
			}

            double SparkMaxRelativeEncoder::GetVelocity() {
                return encoder -> GetVelocity();
            }

            bool SparkMaxRelativeEncoder::IsStopped() {
                return encoder -> GetVelocity() == 0;
			}

            void SparkMaxRelativeEncoder::SetMeasurementPeriod(uint32_t period) {
                this -> encoder -> SetMeasurementPeriod(period);
			}

            uint32_t SparkMaxRelativeEncoder::GetMeasurementPeriod() {
                return encoder -> GetMeasurementPeriod();
			}

            void SparkMaxRelativeEncoder::SetSamplesToAverage(int samples) {
                this -> encoder -> SetAverageDepth(samples);
			}

            int SparkMaxRelativeEncoder::GetSamplesToAverage() {
                return encoder -> GetAverageDepth();
			}

            void SparkMaxRelativeEncoder::Reset() {
                this -> encoder -> SetPosition(0);
			}

        }

    }

}