#pragma once

#include <units/velocity.h>

namespace ffrc {

    namespace devices {

        namespace sensors {

            class Speedometer {
                public:

                    virtual units::velocity::meters_per_second_t GetXVelocity() = 0;
                    virtual units::velocity::meters_per_second_t GetYVelocity() = 0;
                    virtual units::velocity::meters_per_second_t GetZVelocity() = 0;

            };

        }

    }

}
