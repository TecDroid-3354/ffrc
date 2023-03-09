#pragma once

#include "motorcontrollers/controllers/MotorController.hh"

#include "util/limits/Threshold.hh"

namespace ffrc {

    namespace motorcontrollers {

        namespace builders {

            template <typename ControllerType, typename BaseController>
            class MotorControllerBuilder {

                static_assert(std::is_base_of<devices::MotorController, ControllerType>::value,
                    "The ControllerType assigned to a MotorControllerBuilder "
                    "via the template must be a base of "
                    "ffrc::motorcontrol::controllers::MotorController"
                );

                static_assert(std::is_base_of<frc::MotorController, BaseController>::value,
                    "Please ensure that the BaseController "
                    "is derived from frc::MotorController "
                    "when making a ffrc::motorcontrol::controllers::MotorControllerBuilder"
                );

                public:
                    virtual MotorControllerBuilder<ControllerType, BaseController>* SpeedLimitThreshold(util::Threshold) = 0;
                    virtual MotorControllerBuilder<ControllerType, BaseController>* SpeedOutputMultiplier(double)        = 0;
                    virtual MotorControllerBuilder<ControllerType, BaseController>* Invert()                             = 0;

                    virtual ControllerType Build() = 0;

                protected:
                    util::Threshold speedLimitThreshold = util::Threshold(-1.0, 1.0);
                    double speedOutputMultiplier = 1.0;
                    bool isInverted = false;
            };

            template <typename ControllerType, typename BaseController>
            class PWMMotorControllerBuilder: virtual public MotorControllerBuilder<ControllerType, BaseController> {
                public:
                    virtual PWMMotorControllerBuilder<ControllerType, BaseController>* Port(int pwmPort) = 0;

                protected:
                    int pwmPort = 0;
            };

            template <typename ControllerType, typename BaseController>
            class CANMotorControllerBuilder: virtual public MotorControllerBuilder<ControllerType, BaseController> {
                public:
                    virtual CANMotorControllerBuilder<ControllerType, BaseController>* Id(int canId) = 0;

                protected:
                int canId = 0;
            };

        }

    }

}
