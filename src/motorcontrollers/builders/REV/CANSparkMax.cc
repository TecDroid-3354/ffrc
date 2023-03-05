#include "motorcontrollers/builders/REV/CANSparkMax.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            CANSparkMaxBuilder &CANSparkMaxBuilder::MotorType(rev::CANSparkMax::MotorType type) {
                this -> type = type;
                return *this;
            }

            controllers::CANSparkMax CANSparkMaxBuilder::Build() {
                std::unique_ptr<rev::CANSparkMax> spark =
                    std::make_unique<rev::CANSparkMax>(id, type);

                return controllers::CANSparkMax{std::move(spark)};
            }

        }

    }

}
