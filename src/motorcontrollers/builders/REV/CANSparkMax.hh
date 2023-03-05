#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH
#define FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH

#include "motorcontrollers/builders/MotorControllerBuilder.hh"
#include "motorcontrollers/controllers/REV/CANSparkMax.hh"

#include <rev/CANSparkMax.h>

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            class CANSparkMaxBuilder: CANMotorControllerBuilder<controllers::CANSparkMax> {
                public:
                    CANSparkMaxBuilder &MotorType(rev::CANSparkMax::MotorType);
                    controllers::CANSparkMax Build() override;

                protected:
                    rev::CANSparkMax::MotorType type = rev::CANSparkMax::MotorType::kBrushless;
            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH
