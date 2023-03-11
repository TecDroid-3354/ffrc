#include "MotorController.hh"

namespace ffrc {

    namespace motorcontrollers {
        
        namespace devices {

            void MotorController::SetSpeedThreshold(util::Threshold threshold) {
                this -> speedThreshold = threshold;
            }

            util::Threshold MotorController::GetSpeedThreshold() {
                return this -> speedThreshold;
            }

            void MotorController::SetSpeedOutputMultiplier(double multiplier) {
                speedOutputMultiplier = multiplier;
            }

            double MotorController::GetSpeedOutputMultiplier() {
                return this -> speedOutputMultiplier;
            }

        }

    }

}
