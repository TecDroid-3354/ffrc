#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_MOTOR_CONTROLLER_BUILDER_HH
#define FFRC_MOTORCONTROLLERS_BUILDERS_MOTOR_CONTROLLER_BUILDER_HH

#include "motorcontrollers/controllers/MotorController.hh"

#include "util/limits/Threshold.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            template <typename ControllerType>
            class MotorControllerBuilder {

                static_assert(std::is_base_of<controllers::MotorController, ControllerType>::value,
                    "The ControllerType assigned to a MotorControllerBuilder "
                    "via the template must be a base of "
                    "ffrc::motorcontrol::controllers::MotorController"
                );

                public:
                    MotorControllerBuilder<ControllerType> &SpeedLimitThreshold(util::Threshold);
                    MotorControllerBuilder<ControllerType> &SpeedOutputMultiplier(double);

                    virtual ControllerType Build() = 0;

                protected:
                    double speedOutputMultiplier = 1.0;
                    util::Threshold speedLimitThreshold = util::Threshold{-1.0, 1.0};
            };

            template <typename ControllerType>
            class PWMMotorControllerBuilder: MotorControllerBuilder<ControllerType> {
                public:
                    PWMMotorControllerBuilder<ControllerType> &Port(int port);
                 
                protected:
                    int port = 0;
            };

            template <typename ControllerType>
            class CANMotorControllerBuilder: MotorControllerBuilder<ControllerType> {
                public:
                    CANMotorControllerBuilder<ControllerType> &ID(int id);

                protected:
                    int id = 0;
            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_MOTOR_CONTROLLER_BUILDER_HH
