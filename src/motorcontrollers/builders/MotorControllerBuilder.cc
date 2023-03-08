#include "motorcontrollers/builders/MotorControllerBuilder.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            template <typename ControllerType, typename BaseController> 
            MotorControllerBuilder<ControllerType, BaseController>& MotorControllerBuilder<ControllerType, BaseController>::SpeedLimitThreshold(util::Threshold threshold) {
                speedLimitThreshold = threshold;
                return *this;
            }

            template <typename ControllerType, typename BaseController> 
            MotorControllerBuilder<ControllerType, BaseController>& MotorControllerBuilder<ControllerType, BaseController>::SpeedOutputMultiplier(double multiplier) {
                speedOutputMultiplier = multiplier;
                return *this;
            }

            template <typename ControllerType, typename BaseController> 
            MotorControllerBuilder<ControllerType, BaseController>& MotorControllerBuilder<ControllerType, BaseController>::Invert() {
                isInverted = true;
                return *this;
            }

            template <typename ControllerType, typename BaseController> 
            PWMMotorControllerBuilder<ControllerType, BaseController>& PWMMotorControllerBuilder<ControllerType, BaseController>::Port(int pwmPort) {
                this -> pwmPort = pwmPort;
                return *this;
            }

            template <typename ControllerType, typename BaseController> 
            CANMotorControllerBuilder<ControllerType, BaseController>& CANMotorControllerBuilder<ControllerType, BaseController>::Id(int pwmPort) {
                this -> canId = canId;
                return *this;
            }
 
        }

    }

}
