#include "motorcontrollers/builders/CTRE/VictorSPX.hh"

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

            controllers::VictorSPX VictorSPXBuilder::Build() {
                controllers::VictorSPX victorspx{std::make_unique<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(canId)};

                victorspx.SetInversionState(isInverted);
                victorspx.SetSpeedOutputMultiplier(speedOutputMultiplier);
                victorspx.SetSpeedThreshold(speedLimitThreshold);

                return victorspx;
            }

        }

    }

}
