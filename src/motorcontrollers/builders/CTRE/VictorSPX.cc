#include "VictorSPX.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            VictorSPXBuilder& VictorSPXBuilder::SpeedLimitThreshold(util::Threshold threshold) {
                this -> speedLimitThreshold = threshold;
                return *this;
            }

            VictorSPXBuilder& VictorSPXBuilder::SpeedOutputMultiplier(double multiplier) {
                this -> speedOutputMultiplier = multiplier;
                return *this;
            }

            VictorSPXBuilder& VictorSPXBuilder::Invert() {
                this -> isInverted = true;
                return *this;
            }

            VictorSPXBuilder& VictorSPXBuilder::Id(int id) {
                this -> canId = id;
                return *this;
            }

            VictorSPXBuilder& VictorSPXBuilder::ControlMode(ctre::phoenix::motorcontrol::VictorSPXControlMode mode) {
                this -> controlMode = mode;
                return *this;
            }

            controllers::VictorSPX VictorSPXBuilder::Build() {
                auto victorspx = std::make_unique<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(canId);

                controllers::VictorSPX victorspxController{std::move(victorspx)};
                victorspxController.SetInversionState(isInverted);
                victorspxController.SetSpeedOutputMultiplier(speedOutputMultiplier);
                victorspxController.SetSpeedThreshold(speedLimitThreshold);

                victorspxController.SetControlMode(controlMode);

                return victorspxController;
            }

        }

    }

}
