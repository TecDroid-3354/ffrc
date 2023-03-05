#include "MotorController.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            MotorController::MotorController(std::unique_ptr<frc::MotorController> controller): controller(std::move(controller)) {}

            MotorController::~MotorController() = default;

            void MotorController::SetMotorSpeed(double speed) {

                // Branchless version of tesing wether the speed is in the
                // Threshold or not (See Threshold::operator[](double))
                controller->Set(speed * outputSpeedMultiplier * motorSpeedThreshold[std::abs(speed)]);
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

            bool MotorController::GetInversionState() {
                return controller->GetInverted();
            }

            void MotorController::SetMotorSpeedThreshold(util::Threshold threshold) {
                motorSpeedThreshold = threshold;
            }

            util::Threshold MotorController::GetMotorSpeedThreshold() {
                return motorSpeedThreshold;
            }

            void MotorController::SetOutputSpeedMultipler(double multiplier) {
                outputSpeedMultiplier = multiplier;
            }

            double MotorController::GetOutputSpeedMultipler() {
                return outputSpeedMultiplier;
            }

        }
    }

}
