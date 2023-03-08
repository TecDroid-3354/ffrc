#pragma once

#include "motorcontrollers/controllers/MotorController.hh"

#include <rev/CANSparkMax.h>

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            class CANSparkMax: public MotorController {
                public:
                    CANSparkMax(std::unique_ptr<rev::CANSparkMax>);
            };

        }

    }

}
