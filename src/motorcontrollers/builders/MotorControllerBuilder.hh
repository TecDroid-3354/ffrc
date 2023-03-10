#pragma once

#include "motorcontrollers/controllers/MotorController.hh"

#include "util/limits/Threshold.hh"

namespace ffrc {

    namespace motorcontrollers {

        namespace builders {

            template <typename ControllerType>
            class MotorControllerBuilder {

                static_assert(std::is_base_of<devices::MotorController, ControllerType>::value,
                    "The ControllerType assigned to a MotorControllerBuilder "
                    "via the template must be a base of "
                    "ffrc::motorcontrol::controllers::MotorController"
                );

                public:
                    virtual MotorControllerBuilder<ControllerType>* SpeedLimitThreshold(util::Threshold) = 0;
                    virtual MotorControllerBuilder<ControllerType>* SpeedOutputMultiplier(double)        = 0;
                    virtual MotorControllerBuilder<ControllerType>* Invert()                             = 0;

                protected:
                    util::Threshold speedLimitThreshold{-1.0, 1.0};
                    double speedOutputMultiplier = 1.0;
                    bool isInverted = false;
            };

            template <typename ControllerType>
            class PWMMotorControllerBuilder: virtual public MotorControllerBuilder<ControllerType> {
                public:
                    virtual PWMMotorControllerBuilder<ControllerType>* Port(int pwmPort) = 0;

                protected:
                    int pwmPort = 0;
            };

            template <typename ControllerType>
            class CANMotorControllerBuilder: virtual public MotorControllerBuilder<ControllerType> {
                public:
                    virtual CANMotorControllerBuilder<ControllerType>* Id(int canId) = 0;

                protected:
                int canId = 0;
            };

        }

    }

}
