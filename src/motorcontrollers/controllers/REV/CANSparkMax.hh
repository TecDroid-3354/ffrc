#ifndef FFRC_MOTORCONTROLLERS_CONTROLLERS_CAN_SPARK_MAX_HH
#define FFRC_MOTORCONTROLLERS_CONTROLLERS_CAN_SPARK_MAX_HH

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

#endif//FFRC_MOTORCONTROLLERS_CONTROLLERS_CAN_SPARK_MAX_HH