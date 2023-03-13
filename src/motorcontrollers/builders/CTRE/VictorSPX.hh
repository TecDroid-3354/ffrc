#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPXHH
#define FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPX_HH

#include "motorcontrollers/builders/MotorControllerBuilder.hh"
#include "motorcontrollers/devices/CTRE/VictorSPX.hh"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

namespace ffrc {

    namespace builders {

        namespace motorcontrollers {

            class VictorSPX: public CANMotorControllerBuilder<devices::motorcontrollers::VictorSPX> {
                public:
                    VictorSPX* SpeedLimitThreshold(util::Threshold) override;
                    VictorSPX* SpeedOutputMultiplier(double) override;
                    VictorSPX* Invert() override;

                    VictorSPX* Id(int) override;

                    VictorSPX* ControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode);

                    devices::motorcontrollers::VictorSPX Build();

                    private:
                        ctre::phoenix::motorcontrol::VictorSPXControlMode controlMode =
                            ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput;
            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPX_HH
