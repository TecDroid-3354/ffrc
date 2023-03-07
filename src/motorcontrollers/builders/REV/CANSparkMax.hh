#ifndef FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH
#define FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH

#include "motorcontrollers/builders/MotorControllerBuilder.hh"
#include "motorcontrollers/controllers/REV/CANSparkMax.hh"

#include <rev/CANSparkMax.h>

#include <units/current.h>
#include <units/voltage.h>

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            class CANSparkMaxBuilder: public CANMotorControllerBuilder<controllers::CANSparkMax, rev::CANSparkMax> {
                public:
                    CANSparkMaxBuilder& SpeedLimitThreshold(util::Threshold);
                    CANSparkMaxBuilder& SpeedOutputMultiplier(double);
                    CANSparkMaxBuilder& Invert();

                    CANSparkMaxBuilder& Id(int);

                    CANSparkMaxBuilder& MotorType(rev::CANSparkMax::MotorType);
                    CANSparkMaxBuilder& CurrentLimit(units::current::ampere_t);
                    CANSparkMaxBuilder& IdleMode(rev::CANSparkMax::IdleMode);
                    CANSparkMaxBuilder& OpenLoopRampRate(units::time::second_t);
                    CANSparkMaxBuilder& ClosedLoopRampRate(units::time::second_t);
                    CANSparkMaxBuilder& FollowOther(std::shared_ptr<rev::CANSparkMax>, bool = false);
                    CANSparkMaxBuilder& FollowExternal(std::shared_ptr<rev::CANSparkMax::ExternalFollower>, int, bool = false);
                    CANSparkMaxBuilder& CANTimeout(units::time::millisecond_t);
                    CANSparkMaxBuilder& SoftLimit(rev::CANSparkMax::SoftLimitDirection, double);
                    CANSparkMaxBuilder& VoltageCompensation(units::voltage::volt_t);

                    CANSparkMaxBuilder& EnableVoltageCompensation();
                    CANSparkMaxBuilder& EnableSoftLimit();


                    controllers::CANSparkMax Build() override;

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
                    bool reverseFollowTarget     = false;

            };

        }

    }

}

#endif//FFRC_MOTORCONTROLLERS_BUILDERS_CAN_SPARK_MAX_HH
