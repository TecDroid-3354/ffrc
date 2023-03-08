#include "VictorSPX.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            VictorSPX::VictorSPX(std::unique_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> controller):
            MotorController(std::move(controller)) {}

            void VictorSPX::SetMotorSpeed(double speed) {
                reinterpret_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX*>(controller.get()) ->
                    Set(controlMode, util::ClampValueInThreshold(speedThreshold, speed * speedOutputMultiplier));
            }

            void VictorSPX::SetControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode mode) {
                this -> controlMode = mode;
            }
        }

    }

}
