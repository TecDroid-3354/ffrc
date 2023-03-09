#include "VictorSPX.hh"

namespace ffrc {

    namespace motorcontrollers {

        namespace builders {

            VictorSPX* VictorSPX::SpeedLimitThreshold(util::Threshold threshold) {
                this -> speedLimitThreshold = threshold;
                return this;
            }

            VictorSPX* VictorSPX::SpeedOutputMultiplier(double multiplier) {
                this -> speedOutputMultiplier = multiplier;
                return this;
            }

            VictorSPX* VictorSPX::Invert() {
                this -> isInverted = true;
                return this;
            }

            VictorSPX* VictorSPX::Id(int id) {
                this -> canId = id;
                return this;
            }

            VictorSPX* VictorSPX::ControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode mode) {
                this -> controlMode = mode;
                return this;
            }

            devices::VictorSPX VictorSPX::Build() {
                auto victorspx = std::make_unique<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(canId);

                devices::VictorSPX victorspxController{std::move(victorspx)};
                victorspxController.SetInversionState(isInverted);
                victorspxController.SetSpeedOutputMultiplier(speedOutputMultiplier);
                victorspxController.SetSpeedThreshold(speedLimitThreshold);

                victorspxController.SetControlMode(controlMode);

                return victorspxController;
            }

        }

    }

}
