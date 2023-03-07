#include "motorcontrollers/builders/REV/CANSparkMax.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            CANSparkMaxBuilder& CANSparkMaxBuilder::MotorType(rev::CANSparkMax::MotorType type) {
                this -> type = type;
                return *this;
            }

            controllers::CANSparkMax CANSparkMaxBuilder::Build() {
                controllers::CANSparkMax spark{std::make_unique<rev::CANSparkMax>(canId, type)};

                spark.SetInversionState(isInverted);
                spark.SetSpeedOutputMultiplier(speedOutputMultiplier);
                spark.SetSpeedThreshold(speedLimitThreshold);

                return spark;
            }

        }

    }

}
