#pragma once

#include "encoders/builders/MotorEncoderBuilder.hh"
#include "encoders/devices/REV/SparkMaxRelativeEncoder.hh"

namespace ffrc {

    namespace encoders {

        namespace builders {

            class SparkMaxRelativeEncoder: MotorEncoderBuilder<devices::SparkMaxRelativeEncoder> {

                devices::SparkMaxRelativeEncoder Build() override;

            };

        }

    }

}