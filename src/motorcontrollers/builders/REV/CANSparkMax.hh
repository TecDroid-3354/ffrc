#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH
#define FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH

#include "motorcontrollers/builders/MotorControllerBuilder.hh"
#include "motorcontrollers/controllers/REV/CANSparkMax.hh"

#include <rev/CANSparkMax.h>

#include <units/current.h>
#include <units/voltage.h>

namespace ffrc {

    namespace motorcontrollers {

        namespace builders {

            class CANSparkMax: public CANMotorControllerBuilder<devices::CANSparkMax, rev::CANSparkMax> {
                public:
                    CANSparkMax* SpeedLimitThreshold(util::Threshold) override;
                    CANSparkMax* SpeedOutputMultiplier(double)        override;
                    CANSparkMax* Invert()                             override;

                    CANSparkMax* Id(int)                              override;

                    CANSparkMax* MotorType(rev::CANSparkMax::MotorType);
                    CANSparkMax* CurrentLimit(units::current::ampere_t);
                    CANSparkMax* IdleMode(rev::CANSparkMax::IdleMode);
                    CANSparkMax* OpenLoopRampRate(units::time::second_t);
                    CANSparkMax* ClosedLoopRampRate(units::time::second_t);
                    CANSparkMax* FollowOther(std::shared_ptr<rev::CANSparkMax>, bool = false);
                    CANSparkMax* FollowExternal(std::shared_ptr<rev::CANSparkMax::ExternalFollower>, int, bool = false);
                    CANSparkMax* CANTimeout(units::time::millisecond_t);
                    CANSparkMax* SoftLimit(rev::CANSparkMax::SoftLimitDirection, double);
                    CANSparkMax* VoltageCompensation(units::voltage::volt_t);

                    CANSparkMax* EnableVoltageCompensation();
                    CANSparkMax* EnableSoftLimit();

                    devices::CANSparkMax Build() override;

                protected:
                    rev::CANSparkMax::MotorType          motorType          = rev::CANSparkMax::MotorType::kBrushless;
                    rev::CANSparkMax::IdleMode           idleMode           = rev::CANSparkMax::IdleMode::kCoast;
                    rev::CANSparkMax::SoftLimitDirection softLimitDirection = rev::CANSparkMax::SoftLimitDirection::kForward;

                    std::shared_ptr<rev::CANSparkMax>                   followOther;
                    std::shared_ptr<rev::CANSparkMax::ExternalFollower> followObj;

                    units::time::second_t openLoopRampRate   = 0_s;
                    units::time::second_t closedLoopRampRate = 0_s;

                    units::voltage::volt_t     voltageCompensation = 0_V;
                    units::current::ampere_t   currentLimit        = 60_A;
                    units::time::millisecond_t canTimeout          = 0_ms;

                    double softLimit = 0.0;

                    bool enableVoltageCompensation = false;
                    bool enableSoftLimit           = false;
                    bool reverseFollowTarget       = false;

            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH
