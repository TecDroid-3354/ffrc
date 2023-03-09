#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPXHH
#define FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPX_HH

#include "motorcontrollers/builders/MotorControllerBuilder.hh"
#include "motorcontrollers/controllers/CTRE/VictorSPX.hh"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

namespace ffrc {

    namespace motorcontrollers {

        namespace builders {

            class VictorSPX: public CANMotorControllerBuilder<devices::VictorSPX, ctre::phoenix::motorcontrol::can::WPI_VictorSPX> {
                public:
                    VictorSPX* SpeedLimitThreshold(util::Threshold) override;
                    VictorSPX* SpeedOutputMultiplier(double) override;
                    VictorSPX* Invert() override;

                    VictorSPX* Id(int) override;

                    VictorSPX* ControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode);

                    devices::VictorSPX Build() override;

                    private:
                        ctre::phoenix::motorcontrol::VictorSPXControlMode controlMode =
                            ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput;
            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPX_HH
