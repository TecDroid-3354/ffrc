#include "VictorSPX.hh"

namespace ffrc {

    namespace builders {

        namespace motorcontrollers {

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

            std::shared_ptr<devices::motorcontrollers::VictorSPX> VictorSPX::Build() {
                auto victorspx = std::make_unique<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(canId);

                std::shared_ptr<devices::motorcontrollers::VictorSPX> victorspxController =
                    std::make_shared<devices::motorcontrollers::VictorSPX>(std::move(victorspx));

                victorspxController -> SetInversionState(isInverted);
                victorspxController -> SetSpeedOutputMultiplier(speedOutputMultiplier);
                victorspxController -> SetSpeedThreshold(speedLimitThreshold);

                victorspxController -> SetControlMode(controlMode);

                return victorspxController;
            }

        }

    }

}
