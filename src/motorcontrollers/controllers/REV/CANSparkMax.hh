#pragma once

#include "motorcontrollers/controllers/MotorController.hh"

#include <rev/CANSparkMax.h>

namespace ffrc {

    namespace motorcontrollers {

        namespace devices {

            class CANSparkMax: public MotorController {
                public:
                    CANSparkMax(std::unique_ptr<rev::CANSparkMax>);

                    void    SetMotorSpeed(double)                    override;
                    void    SetOutputVoltage(units::voltage::volt_t) override;
                    double  GetMotorSpeed()                          override;

                    void    StopMotor()                              override;
                    void    DisableMotor()                           override;

                    void    SetInversionState(bool isInverted)       override;
                    void    Invert()                                 override;
                    bool    GetInversionState()                      override;
                
                private:
                    std::unique_ptr<rev::CANSparkMax> controller;
            };

        }

    }

}
