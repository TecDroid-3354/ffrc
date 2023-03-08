#include "GenericEncoder.hh"

namespace ffrc {

    namespace encoders {
        GenericEncoder::GenericEncoder(std::unique_ptr<frc::Encoder> encoder, unsigned int resolution):
        MotorEncoder(resolution), encoder(std::move(encoder)) {}

        void GenericEncoder::SetDistancePerPulse(double distance) {
            encoder -> SetDistancePerPulse(distance);
        }

        void GenericEncoder::SetMinRate(double distancePerSecond) {
            encoder -> SetMinRate(distancePerSecond);
        }

        void GenericEncoder::SetSamplesToAverage(int samplesToAverage) {
            encoder -> SetSamplesToAverage(samplesToAverage);
        }

        void GenericEncoder::Invert() {
            encoder -> SetReverseDirection(true);
        }

        bool GenericEncoder::IsLastMovementForward() {
            return encoder -> GetDirection();
        }

        bool GenericEncoder::IsStopped() {
            return encoder -> GetStopped();
        }

        void GenericEncoder::Reset() {
            encoder -> Reset();
        }

        int GenericEncoder::GetCount() {
            return encoder -> Get();
        }

        double GenericEncoder::GetDistance() {
            return encoder -> GetDistance();
        }

        double GenericEncoder::GetDistancePerPulse() {
            return encoder -> GetDistancePerPulse();
        }

        double GenericEncoder::GetRate() {
            return encoder -> GetRate();
        }

        int GenericEncoder::GetEncodingScale() {
            return encoder -> GetEncodingScale();
        }

        int GenericEncoder::GetFPGAIndex() {
            return encoder -> GetFPGAIndex();
        }

        int GenericEncoder::GetRawValue() {
            return encoder -> GetRaw();
        }

    }
}