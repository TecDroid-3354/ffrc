#include "AMT103.hh"

namespace ffrc {

    namespace encoders {

        namespace builders {

            AMT103* AMT103::SetResolution(uint32_t resolution) {
                this -> resolution = resolution;
                return this;
            }

            AMT103* AMT103::SetPositionConversionFactor(double factor) {
                this -> positionConversionFactor = factor;
                return this;
            }

            AMT103* AMT103::StartWithDistance(double distance) {
                this -> startingDistance = distance;
                return this;
            }

            AMT103* AMT103::SetSwitchConfiguration(bool a, bool b, bool c, bool d) {
                this -> resolution = 2048 / (a || b || c || d) ? (
                    (AMT103SwitchValues::SWITCH_ONE   * a) * //
                    (AMT103SwitchValues::SWITCH_TWO   * b) * //
                    (AMT103SwitchValues::SWITCH_THREE * c) * //
                    (AMT103SwitchValues::SWITCH_FOUR  * d)   //
                ) : 1;

                return this;
            }

            AMT103* AMT103::AChannel(int channel) {
                this -> aChannel = channel;
                return this;
            }

            AMT103* AMT103::BChannel(int channel) {
                this -> bChannel = channel;
                return this;
            }

            AMT103* AMT103::ReverseDirection(bool reverse) {
                this -> reverseDirection = reverse;
                return this;
            }

            AMT103* AMT103::EncodingType(frc::Encoder::EncodingType type) {
                this -> encodingType = type;
                return this;
            }

            std::shared_ptr<devices::AMT103> AMT103::Build() {
                std::unique_ptr<frc::Encoder> genEncoder = std::make_unique<frc::Encoder>(aChannel, bChannel, reverseDirection, encodingType);

                std::shared_ptr<devices::AMT103> amt103 = std::make_shared<devices::AMT103>(std::move(genEncoder));

                amt103 -> SetPositionConversionFactor(positionConversionFactor);
                amt103 -> SetResolution(resolution);
                amt103 -> SetTraveledDistance(startingDistance);

                return amt103;
            }

        }

    }

}
