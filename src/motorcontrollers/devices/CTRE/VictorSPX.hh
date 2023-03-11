#pragma once

#include "motorcontrollers/devices/MotorController.hh"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

namespace ffrc {

    namespace devices {

        namespace motorcontrollers {

            class VictorSPX: public MotorController {
                public:
                    VictorSPX(std::unique_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>);

                    void    SetMotorSpeed(double)                    override;
                    void    SetOutputVoltage(units::voltage::volt_t) override;
                    double  GetMotorSpeed()                          override;

                    void    StopMotor()                              override;
                    void    DisableMotor()                           override;

                    void    SetInversionState(bool isInverted)       override;
                    void    Invert()                                 override;
                    bool    GetInversionState()                      override;

                    void SetControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode);

                protected:
                    std::unique_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> controller;
                    ctre::phoenix::motorcontrol::VictorSPXControlMode controlMode = ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput;
            };

        }

    }

}
