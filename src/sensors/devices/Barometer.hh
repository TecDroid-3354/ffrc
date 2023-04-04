#pragma once

#include <units/pressure.h>

namespace ffrc {

    namespace devices {

        namespace sensors {

            class Barometer {
                public:

                    virtual units::pressure::bar_t GetPressure() = 0;

            };

        }

    }

}
