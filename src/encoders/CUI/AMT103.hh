#pragma once

#include "encoders/generic/GenericEncoder.hh"

namespace ffrc {

    namespace encoders {

        namespace AMT103ResolutionModifiers {
            constexpr double SWITCH_ONE   = 2048.0 / 1000.0;
            constexpr double SWITCH_TWO   = 2048.0 / 800.0;
            constexpr double SWITCH_THREE = 2048.0 / 1024.0;
            constexpr double SWITCH_FOUR  = 2048.0 / 512.0;
        }

        class AMT103: public GenericEncoder {
            public:

                AMT103(std::unique_ptr<frc::Encoder>);

                void SetInternalPinConfiguration(bool, bool, bool, bool);

        };

    }

}
