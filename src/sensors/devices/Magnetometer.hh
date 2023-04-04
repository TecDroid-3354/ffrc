#pragma once

#include <units/magnetic_field_strength.h>
#include <units/angle.h>

namespace ffrc {

    namespace devices {

        namespace sensors {

            class Magnetometer {
                public:

                    virtual units::angle::degree_t GetCompassRotation() = 0;
                    virtual units::magnetic_field_strength::tesla_t GetXFieldStrength() = 0;
                    virtual units::magnetic_field_strength::tesla_t GetYFieldStrength() = 0;
                    virtual units::magnetic_field_strength::tesla_t GetZFieldStrength() = 0;

            };

        }

    }

}
