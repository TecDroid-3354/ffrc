
#pragma once

namespace ffrc {

    namespace encoders {

        namespace builders {

            template <typename EncoderType>
            class MotorEncoderBuilder {
                public:

                    virtual EncoderType Build() = 0;

            };

        }

    }

}