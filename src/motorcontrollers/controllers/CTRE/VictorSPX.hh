#pragma once

#include "motorcontrollers/controllers/MotorController.hh"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            class VictorSPX: public MotorController {
                public:
                    VictorSPX(std::unique_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>);

                    void SetMotorSpeed(double);
                    void SetControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode);

                protected:
                    ctre::phoenix::motorcontrol::VictorSPXControlMode controlMode = ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput;
            };

        }

    }

}
