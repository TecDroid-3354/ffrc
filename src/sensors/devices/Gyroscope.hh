#pragma once

#include <units/angle.h>

namespace ffrc {

    namespace devices {

        namespace sensors {

            class Gyroscope {
                public:

                    virtual units::angle::degree_t GetXRotation() = 0;
                    virtual units::angle::degree_t GetYRotation() = 0;
                    virtual units::angle::degree_t GetZRotation() = 0;

                    virtual void ResetXRotation() = 0;
                    virtual void ResetYRotation() = 0;
                    virtual void ResetZRotation() = 0;

            };

        }

    }

}
