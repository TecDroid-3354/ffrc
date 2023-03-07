#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPXHH
#define FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPX_HH

#include "motorcontrollers/builders/MotorControllerBuilder.hh"
#include "motorcontrollers/controllers/CTRE/VictorSPX.hh"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            class VictorSPXBuilder: public CANMotorControllerBuilder<controllers::VictorSPX, ctre::phoenix::motorcontrol::can::WPI_VictorSPX> {
                public:
                    VictorSPXBuilder& SpeedLimitThreshold(util::Threshold);
                    VictorSPXBuilder& SpeedOutputMultiplier(double);
                    VictorSPXBuilder& Invert();

                    VictorSPXBuilder& Id(int);

                    controllers::VictorSPX Build() override;
            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_VICTOR_SPX_HH
