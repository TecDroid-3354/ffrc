#pragma once

#include "encoders/builders/MotorEncoderBuilder.hh"
#include "encoders/devices/CUI/AMT103.hh"

namespace ffrc {

    namespace encoders {

        namespace builders {

            namespace AMT103SwitchValues {
                constexpr double SWITCH_ONE   = 2048.0 / 1000.0;
                constexpr double SWITCH_TWO   = 2048.0 /  800.0;
                constexpr double SWITCH_THREE = 2048.0 / 1024.0;
                constexpr double SWITCH_FOUR  = 2048.0 / 512.0;
            }

            class AMT103: public MotorEncoderBuilder<devices::AMT103> {
                public:
                    AMT103* SetResolution(long double)          override;
                    AMT103* SetPositionConversionFactor(double) override;
                    AMT103* StartWithDistance(double)           override;

                    AMT103* AChannel(int);
                    AMT103* BChannel(int);
                    AMT103* ReverseDirection(bool);
                    AMT103* EncodingType(frc::Encoder::EncodingType);

                    AMT103* SetSwitchConfiguration(bool, bool, bool, bool);

                    std::shared_ptr<devices::AMT103> Build();

                private:
                    std::unique_ptr<frc::Encoder> encoder;

                    int aChannel = 0;
                    int bChannel = 1;
                    bool reverseDirection = false;
                    frc::Encoder::EncodingType encodingType = frc::Encoder::EncodingType::k4X;

            };

        }

    }

}
