#include "VictorSPX.hh"

namespace ffrc {

    namespace motorcontrollers {

        namespace devices {

            VictorSPX::VictorSPX(std::unique_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> controller):
            controller(std::move(controller)) {}

            void VictorSPX::SetMotorSpeed(double speed) {
                controller -> Set(controlMode, util::ClampValueInThreshold(speedThreshold, speed * speedOutputMultiplier));
            }

            void VictorSPX::SetOutputVoltage(units::voltage::volt_t voltage) {
                controller -> SetVoltage(voltage);
            }

            double VictorSPX::GetMotorSpeed() {
                return controller -> Get();
            }

            void VictorSPX::StopMotor() {
                controller -> StopMotor();
            }

            void VictorSPX::DisableMotor() {
                controller -> Disable();
            }

            void VictorSPX::SetInversionState(bool inverted) {
                controller -> SetInverted(inverted);
            }

            void VictorSPX::Invert() {
                SetInversionState(true);
            }

            bool VictorSPX::GetInversionState() {
                return controller -> GetInverted();
            }

            void VictorSPX::SetControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode mode) {
                this -> controlMode = mode;
            }

        }

    }

}
