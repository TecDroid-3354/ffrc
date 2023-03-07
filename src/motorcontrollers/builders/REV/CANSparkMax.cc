#include "motorcontrollers/builders/REV/CANSparkMax.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            CANSparkMaxBuilder& CANSparkMaxBuilder::SpeedLimitThreshold(util::Threshold threshold) {
                this -> speedLimitThreshold = threshold;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::SpeedOutputMultiplier(double multiplier) {
                this -> speedOutputMultiplier = multiplier;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::Invert() {
                this -> isInverted = true;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::Id(int id) {
                this -> canId = id;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::MotorType(rev::CANSparkMax::MotorType type) {
                this -> motorType = type;
                return *this;
            }

            controllers::CANSparkMax CANSparkMaxBuilder::Build() {
                controllers::CANSparkMax spark{std::make_unique<rev::CANSparkMax>(canId, motorType)};

                spark.SetInversionState(isInverted);
                spark.SetSpeedOutputMultiplier(speedOutputMultiplier);
                spark.SetSpeedThreshold(speedLimitThreshold);

                return spark;
            }

        }

    }

}
