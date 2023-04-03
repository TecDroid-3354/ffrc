#pragma once

#include <units/length.h>

namespace ffrc {

    namespace devices {

        namespace sensors {

            class Gyroscope {
                public:

                    virtual units::length::meter_t GetXDisplacement() = 0;
                    virtual units::length::meter_t GetYDisplacement() = 0;
                    virtual units::length::meter_t GetZDisplacement() = 0;

                    virtual void ResetXDisplacement() = 0;
                    virtual void ResetYDisplacement() = 0;
                    virtual void ResetZDisplacement() = 0;

            };

        }

    }

}
