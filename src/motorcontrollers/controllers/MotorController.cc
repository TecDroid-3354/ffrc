#include "MotorController.hh"

#include <algorithm>

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            MotorController::MotorController(std::unique_ptr<frc::MotorController> controller): controller(std::move(controller)) {}

            void MotorController::SetMotorSpeed(double speed) {
                controller->Set(util::ClampValueInThreshold(speedThreshold, speed * speedOutputMultiplier));
            }

            void MotorController::SetOutputVoltage(units::voltage::volt_t voltage) {
                controller->SetVoltage(voltage);
            }

            double MotorController::GetMotorSpeed() {
                return controller->Get();
            }

            void MotorController::StopMotor() {
                controller->StopMotor();
            }

            void MotorController::DisableMotor() {
                controller->Disable();
            }

            void MotorController::SetInversionState(bool inverted) {
                controller->SetInverted(inverted);
            }

            void MotorController::Invert() {
                controller->SetInverted(true);
            }

            bool MotorController::GetInversionState() {
                return controller->GetInverted();
            }

            void MotorController::SetSpeedThreshold(util::Threshold threshold) {
                speedThreshold = threshold;
            }

            util::Threshold MotorController::GetSpeedThreshold() {
                return speedThreshold;
            }

            void MotorController::SetSpeedOutputMultiplier(double multiplier) {
                speedOutputMultiplier= multiplier;
            }

            double MotorController::GetSpeedOutputMultiplier() {
                return speedOutputMultiplier;
            }

        }
    }

}
