#include "motorcontrollers/controllers/CTRE/VictorSPX.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace controllers {

            VictorSPX::VictorSPX(std::unique_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> controller):
            MotorController(std::move(controller)) {}
        }

    }

}
