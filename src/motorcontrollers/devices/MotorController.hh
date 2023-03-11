#pragma once

#include "util/limits/Threshold.hh"

#include <units/velocity.h>
#include <units/voltage.h>

#include <frc/motorcontrol/MotorController.h>

namespace ffrc {

    namespace devices {
        
        namespace motorcontrollers {

            class MotorController {
                public:
                    virtual void    SetMotorSpeed(double)                    = 0;
                    virtual void    SetOutputVoltage(units::voltage::volt_t) = 0;
                    virtual double  GetMotorSpeed()                          = 0;

                    virtual void    StopMotor()                              = 0;
                    virtual void    DisableMotor()                           = 0;

                    virtual void    SetInversionState(bool isInverted)       = 0;
                    virtual void    Invert()                                 = 0;
                    virtual bool    GetInversionState()                      = 0;

                    void            SetSpeedThreshold(util::Threshold);
                    util::Threshold GetSpeedThreshold();

                    void            SetSpeedOutputMultiplier(double multiplier);
                    double          GetSpeedOutputMultiplier();

                protected:
                    double          speedOutputMultiplier = 1.0;
                    util::Threshold speedThreshold        = util::Threshold(-1.0, 1.0);

            };

        }

    }

}
