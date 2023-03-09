#include "CANSparkMax.hh"

namespace ffrc {

    namespace motorcontrollers {

        namespace devices {

            CANSparkMax::CANSparkMax(std::unique_ptr<rev::CANSparkMax> controller):
            controller(std::move(controller)) {}

            void CANSparkMax::SetMotorSpeed(double speed) {
                controller -> Set(util::ClampValueInThreshold(speedThreshold, speed * speedOutputMultiplier));
            }

            void CANSparkMax::SetOutputVoltage(units::voltage::volt_t voltage) {
                controller -> SetVoltage(voltage);
            }

            double CANSparkMax::GetMotorSpeed() {
                return controller -> Get();
            }

            void CANSparkMax::StopMotor() {
                controller -> StopMotor();
            }

            void CANSparkMax::DisableMotor() {
                controller -> Disable();
            }

            void CANSparkMax::SetInversionState(bool inverted) {
                controller -> SetInverted(inverted);
            }

            void CANSparkMax::Invert() {
                SetInversionState(true);
            }

            bool CANSparkMax::GetInversionState() {
                return controller -> GetInverted();
            }

        }

    }

}
