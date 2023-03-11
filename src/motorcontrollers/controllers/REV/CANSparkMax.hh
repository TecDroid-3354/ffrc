#pragma once

#include "motorcontrollers/controllers/MotorController.hh"
#include "encoders/devices/REV/SparkMaxRelativeEncoder.hh"

#include <rev/CANSparkMax.h>

namespace ffrc {

    namespace encoders {

        namespace builders {

            class SparkMaxRelativeEncoder;

        }

    }

    namespace motorcontrollers {

        namespace devices {

            class CANSparkMax: public MotorController {
                friend encoders::builders::SparkMaxRelativeEncoder;

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
                    std::shared_ptr<rev::SparkMaxRelativeEncoder> encoder;

                    std::shared_ptr<rev::SparkMaxRelativeEncoder> GetOrCreateEncoder();

            };

        }

    }

}
