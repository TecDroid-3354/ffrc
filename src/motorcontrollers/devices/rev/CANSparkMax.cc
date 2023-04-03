#include "CANSparkMax.hh"

namespace ffrc {

    namespace devices {

        namespace motorcontrollers {

            CANSparkMax::CANSparkMax(std::unique_ptr<rev::CANSparkMax> controller):
            controller(std::move(controller)), encoder(std::nullptr_t{}) {}

            void CANSparkMax::SetMotorSpeed(double speed) {
                controller -> Set(speedThreshold.Clamp(speed * speedOutputMultiplier));
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

            std::shared_ptr<rev::SparkMaxRelativeEncoder> CANSparkMax::GetOrCreateEncoder() {
                if (encoder.get() == nullptr) {
                    encoder = std::make_shared<rev::SparkMaxRelativeEncoder>(controller -> GetEncoder());
                }

                return encoder;
            }

            frc::MotorController* CANSparkMax::GetImplementation() {
                return controller.get();
            }

        }

    }

}
