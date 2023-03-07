#ifndef FFRC_MOTOR_CONTROLLER_HH
#define FFRC_MOTOR_CONTROLLER_HH

#include "util/limits/Threshold.hh"

#include <units/velocity.h>
#include <units/voltage.h>

#include <frc/motorcontrol/MotorController.h>

namespace ffrc {

    namespace motorcontrol {
        
        namespace controllers {

            class MotorController {
                public:

                    MotorController(std::unique_ptr<frc::MotorController>);

                    void SetMotorSpeed(double);
                    void SetOutputVoltage(units::voltage::volt_t);
                    double GetMotorSpeed();

                    void StopMotor();
                    void DisableMotor();

                    void SetInversionState(bool isInverted);
                    void Invert();
                    bool GetInversionState();

                    void SetSpeedThreshold(util::Threshold);
                    util::Threshold GetSpeedThreshold();

                    void SetSpeedOutputMultiplier(double multiplier);
                    double GetSpeedOutputMultiplier();

                protected:
                    std::unique_ptr<frc::MotorController> controller;

                private:
                    double speedOutputMultiplier = 1.0;
                    util::Threshold speedThreshold = util::Threshold(-1.0, 1.0);
            };

        }
    }
}

#endif//FFRC_MOTOR_CONTROLLER_HH