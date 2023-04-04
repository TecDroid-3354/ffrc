#pragma once

#include <units/acceleration.h>

namespace ffrc {

    namespace devices {

        namespace sensors {

            class Accelerometer {
                public:

                    virtual units::acceleration::meters_per_second_squared_t GetXAcceleration() = 0;
                    virtual units::acceleration::meters_per_second_squared_t GetYAcceleration() = 0;
                    virtual units::acceleration::meters_per_second_squared_t GetZAcceleration() = 0;

            };

        }

    }

}
