#include "SparkMaxRelativeEncoder.hh"

namespace ffrc {

    namespace encoders {

        SparkMaxRelativeEncoder::SparkMaxRelativeEncoder(std::unique_ptr<rev::SparkMaxRelativeEncoder> encoder):
        MotorEncoder(encoder -> GetCountsPerRevolution()), encoder(std::move(encoder)) {}

        void SparkMaxRelativeEncoder::SetDistancePerPulse(double factor) {
            encoder -> SetPositionConversionFactor(factor);
		}

        void SparkMaxRelativeEncoder::SetMinRate(double) {
		}

        void SparkMaxRelativeEncoder::SetSamplesToAverage(int samples) {
            encoder -> SetAverageDepth(samples);
		}

        void SparkMaxRelativeEncoder::Invert() {
            encoder -> SetInverted(true);
		}

        bool SparkMaxRelativeEncoder::IsLastMovementForward() {
            return (lastPosition - encoder -> GetPosition()) > 0;
		}

        bool SparkMaxRelativeEncoder::IsStopped() {
            return encoder -> GetVelocity() == 0;

		}

        void SparkMaxRelativeEncoder::Reset() {
            encoder -> SetPosition(0);
		}

        int SparkMaxRelativeEncoder::GetCount() {
            return encoder -> GetPosition() * encoder -> GetCountsPerRevolution();
		}

        double SparkMaxRelativeEncoder::GetDistance() {
            return encoder -> GetPosition();
		}

        double SparkMaxRelativeEncoder::GetDistancePerPulse() {
            return 1;
		}

        double SparkMaxRelativeEncoder::GetRate() {
            return encoder -> GetVelocity() / 60;
		}

        int SparkMaxRelativeEncoder::GetEncodingScale() {
            return -1;
		}

        int SparkMaxRelativeEncoder::GetRawValue() {
            return GetCount();
		}

        units::time::second_t SparkMaxRelativeEncoder::GetLastPulsePeriod() {
            return units::time::second_t{(double) encoder -> GetMeasurementPeriod()};

		}

    }

}