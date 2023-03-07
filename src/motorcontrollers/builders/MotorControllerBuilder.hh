#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_MOTOR_CONTROLLER_BUILDER_HH
#define FFRC_MOTORCONTROLLERS_BUILDERS_MOTOR_CONTROLLER_BUILDER_HH

#include "motorcontrollers/controllers/MotorController.hh"

#include "util/limits/Threshold.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            template <typename ControllerType, typename BaseController>
            class MotorControllerBuilder {

                static_assert(std::is_base_of<controllers::MotorController, ControllerType>::value,
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

                    MotorControllerBuilder<ControllerType, BaseController>& SpeedLimitThreshold(util::Threshold);
                    MotorControllerBuilder<ControllerType, BaseController>& SpeedOutputMultiplier(double);
                    MotorControllerBuilder<ControllerType, BaseController>& Invert();

                    virtual ControllerType Build() = 0;

                protected:
                    util::Threshold speedLimitThreshold = util::Threshold(-1.0, 1.0);
                    double speedOutputMultiplier = 1.0;
                    bool isInverted = false;
            };

            template <typename ControllerType, typename BaseController>
            class PWMMotorControllerBuilder: virtual public MotorControllerBuilder<ControllerType, BaseController> {
                public:
                    PWMMotorControllerBuilder<ControllerType, BaseController>& Port(int pwmPort);

                protected:
                    int pwmPort = 0;
            };

            template <typename ControllerType, typename BaseController>
            class CANMotorControllerBuilder: virtual public MotorControllerBuilder<ControllerType, BaseController> {
                public:

                    CANMotorControllerBuilder<ControllerType, BaseController>& Id(int canId);

                protected:
                int canId = 0;
            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_MOTOR_CONTROLLER_BUILDER_HH
