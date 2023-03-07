#include "motorcontrollers/controllers/REV/CANSparkMax.hh"

#include <rev/CANSparkMax.h>

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            CANSparkMax::CANSparkMax(std::unique_ptr<rev::CANSparkMax> controller):
            MotorController(std::move(controller)) {}

        }

    }

}
