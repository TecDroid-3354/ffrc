#include "AMT103.hh"

namespace ffrc {

    namespace encoders {

        AMT103::AMT103(std::unique_ptr<frc::Encoder> encoder): GenericEncoder(std::move(encoder), 2048) {}

        void AMT103::SetInternalPinConfiguration(bool switchState1, bool switchState2, bool switchState3, bool switchState4) {
            resolution = 2048 / (switchState1 || switchState2 || switchState3 || switchState4) ? (
                (AMT103ResolutionModifiers::SWITCH_ONE   * switchState1) *
                (AMT103ResolutionModifiers::SWITCH_TWO   * switchState2) *
                (AMT103ResolutionModifiers::SWITCH_THREE * switchState3) *
                (AMT103ResolutionModifiers::SWITCH_FOUR  * switchState4)
            ) : 1;
        }

    }

}