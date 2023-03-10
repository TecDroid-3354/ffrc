#include "SparkMaxRelativeEncoder.hh"

namespace ffrc {
    
    namespace encoders {

        namespace devices {

            SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(std::shared_ptr<rev::SparkMaxRelativeEncoder> encoder):
            encoder(encoder) {}

            void SparkMaxRelativeEncoder::SetResolution(uint32_t distance){
                // Already Handled by the encoder
            }

            double SparkMaxRelativeEncoder::GetResolution() {
                return encoder -> GetCountsPerRevolution();
			}

            void SparkMaxRelativeEncoder::SetPositionConversionFactor(double factor) {
                encoder -> SetPositionConversionFactor(factor);
                positionConversionFactor = factor;
            }

            double SparkMaxRelativeEncoder::GetPositionConversionFactor() {
                return encoder -> GetPositionConversionFactor();
            }

            void SparkMaxRelativeEncoder::SetTraveledDistance(double) {
                encoder -> SetPosition(0);
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
                encoder -> SetMeasurementPeriod(period);
			}

            uint32_t SparkMaxRelativeEncoder::GetMeasurementPeriod() {
                return encoder -> GetMeasurementPeriod();
			}

            void SparkMaxRelativeEncoder::SetSamplesToAverage(int samples) {
                encoder -> SetAverageDepth(samples);
			}

            int SparkMaxRelativeEncoder::GetSamplesToAverage() {
                return encoder -> GetAverageDepth();
			}

            void SparkMaxRelativeEncoder::Reset() {
                encoder -> SetPosition(0);
			}

        }

    }

}