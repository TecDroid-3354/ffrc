#include "AMT103.hh"

namespace ffrc {

    namespace encoders {

        namespace devices {

            AMT103::AMT103(std::unique_ptr<frc::Encoder> encoder):
            encoder(std::move(encoder)) {}

            void AMT103::SetResolution(uint32_t resolution) {
                this -> resolution = resolution;
            }

            double AMT103::GetResolution() {
                return this -> resolution;
            }

            void AMT103::SetPositionConversionFactor(double factor) {
                this -> positionConversionFactor = factor;
                encoder -> SetDistancePerPulse(factor / resolution);
            }

            double AMT103::GetPositionConversionFactor() {
                return positionConversionFactor;
            }

            void AMT103::SetTraveledDistance(double distance) {
                // Unsupported
            }

            double AMT103::GetTraveledDistance() {
                return encoder -> GetDistance();
            }

            double AMT103::GetVelocity() {
                return encoder -> GetRate();
            }

            bool AMT103::IsStopped() {
                return encoder -> GetStopped();
            }

            void AMT103::SetMeasurementPeriod(uint32_t period) {
                // Unsupported
            }

            uint32_t AMT103::GetMeasurementPeriod() {
                // Unsupported
                return 0;
            }

            void AMT103::SetSamplesToAverage(int samples) {
                encoder -> SetSamplesToAverage(samples);
            }

            int AMT103::GetSamplesToAverage() {
                return encoder -> GetSamplesToAverage();
            }

            void AMT103::Reset() {
                encoder -> Reset();
            }

        }

    }

}
