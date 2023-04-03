#pragma once
#include <utility>

#include "encoders/builders/MotorEncoderBuilder.hh"
#include "encoders/devices/rev/SparkMaxRelativeEncoder.hh"
#include "motorcontrollers/devices/rev/CANSparkMax.hh"

namespace ffrc {

    namespace builders {

        namespace encoders {

            class SparkMaxRelativeEncoder: public MotorEncoderBuilder<devices::encoders::SparkMaxRelativeEncoder> {
                public:
                    SparkMaxRelativeEncoder(devices::motorcontrollers::MotorController&);

                    SparkMaxRelativeEncoder* SetResolution(long double)          override;
                    SparkMaxRelativeEncoder* SetPositionConversionFactor(double) override;
                    SparkMaxRelativeEncoder* StartWithDistance(double)           override;

                    devices::encoders::SparkMaxRelativeEncoder Build();

                protected:
                    devices::motorcontrollers::CANSparkMax& from;

            };

        }

    }

}