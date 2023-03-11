#include "AMT103.hh"

namespace ffrc {

    namespace devices {

        namespace encoders {

            AMT103::AMT103(std::unique_ptr<frc::Encoder> encoder):
            encoder(std::move(encoder)) {}

            void AMT103::SetResolution(long double resolution) {
                this -> resolution = resolution;
                this -> encoder -> SetDistancePerPulse(1 / resolution);
            }

            double AMT103::GetResolution() {
                return this -> resolution;
            }

            void AMT103::SetPositionConversionFactor(double factor) {
                this -> positionConversionFactor = factor;
            }

            double AMT103::GetPositionConversionFactor() {
                return positionConversionFactor;
            }

            void AMT103::SetTraveledDistance(double distance) {
                this -> fakeTraveledDistance = distance;
            }

            double AMT103::GetTraveledDistance() {
                return (encoder -> GetDistance() * positionConversionFactor) + fakeTraveledDistance;
            }

            double AMT103::GetVelocity() {
                return encoder -> GetRate();
            }

            bool AMT103::IsStopped() {
                return encoder -> GetStopped();
            }

            void AMT103::SetMeasurementPeriod(uint32_t period) {
                throw std::runtime_error("Cannot modify the measurement period of an AMT103-V");
            }

            uint32_t AMT103::GetMeasurementPeriod() {
                // Formula in the AMT103-V Datasheet
                // Mechanical degrees
                return 360.0 / resolution;
            }

            void AMT103::SetSamplesToAverage(int samples) {
                this -> encoder -> SetSamplesToAverage(samples);
            }

            int AMT103::GetSamplesToAverage() {
                return encoder -> GetSamplesToAverage();
            }

            void AMT103::Reset() {
                this -> encoder -> Reset();
            }

        }

    }

}
