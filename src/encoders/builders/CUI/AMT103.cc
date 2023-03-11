#include "AMT103.hh"

namespace ffrc {

    namespace builders {

        namespace encoders {

            AMT103* AMT103::SetResolution(long double resolution) {
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
                SetResolution(2048 / (
                        (a ? (AMT103SwitchValues::SWITCH_ONE  ) : 1.0) * //
                        (b ? (AMT103SwitchValues::SWITCH_TWO  ) : 1.0) * //
                        (c ? (AMT103SwitchValues::SWITCH_THREE) : 1.0) * //
                        (d ? (AMT103SwitchValues::SWITCH_FOUR ) : 1.0)   //
                    )
                );

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

            std::shared_ptr<devices::encoders::AMT103> AMT103::Build() {
                std::unique_ptr<frc::Encoder> frcEncoder = std::make_unique<frc::Encoder>(aChannel, bChannel, reverseDirection, encodingType);

                std::shared_ptr<devices::encoders::AMT103> amt103 =
                    std::make_shared<devices::encoders::AMT103>(std::move(frcEncoder));

                amt103 -> SetPositionConversionFactor(positionConversionFactor);
                amt103 -> SetResolution(resolution);
                amt103 -> SetTraveledDistance(startingDistance);

                return amt103;
            }

        }

    }

}
