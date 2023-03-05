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
                    void SetMotorSpeed(double);
                    void SetOutputVoltage(units::voltage::volt_t);
                    double GetMotorSpeed();

                    void StopMotor();
                    void DisableMotor();

                    void SetInversionState(bool isInverted);
                    bool GetInversionState();

                    void SetMotorSpeedThreshold(util::Threshold);
                    util::Threshold GetMotorSpeedThreshold();

                    void SetOutputSpeedMultipler(double multiplier);
                    double GetOutputSpeedMultipler();

                protected:
                    MotorController(std::unique_ptr<frc::MotorController> controller);
                    ~MotorController();

                    std::unique_ptr<frc::MotorController> controller;

                private:
                    double outputSpeedMultiplier = 1.0;
                    util::Threshold motorSpeedThreshold = util::Threshold(-1.0, 1.0);
            };

        }
    }
}

#endif//FFRC_MOTOR_CONTROLLER_HH