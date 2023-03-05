#include "motorcontrollers/builders/MotorControllerBuilder.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            template <typename ControllerType>
            MotorControllerBuilder<ControllerType> &MotorControllerBuilder<ControllerType>::SpeedLimitThreshold(util::Threshold threshold) {
                this -> speedLimitThreshold = threshold;
                return *this;
            }

            template <typename ControllerType>
            MotorControllerBuilder<ControllerType> &MotorControllerBuilder<ControllerType>::SpeedOutputMultiplier(double multiplier) {
                this -> speedOutputMultiplier = multiplier;
                return *this;
            }

            template <typename ControllerType>
            PWMMotorControllerBuilder<ControllerType> &PWMMotorControllerBuilder<ControllerType>::Port(int port) {
                this -> port = port;
                return *this;
            }

            template <typename ControllerType>
            CANMotorControllerBuilder<ControllerType> &CANMotorControllerBuilder<ControllerType>::ID(int id) {
                this -> id = id;
                return *this;
            }

        }

    }

}
