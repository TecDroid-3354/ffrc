#include "CANSparkMax.hh"

namespace ffrc {

    namespace motorcontrol {

        namespace builders {

            CANSparkMaxBuilder& CANSparkMaxBuilder::SpeedLimitThreshold(util::Threshold threshold) {
                this -> speedLimitThreshold = threshold;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::SpeedOutputMultiplier(double multiplier) {
                this -> speedOutputMultiplier = multiplier;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::Invert() {
                this -> isInverted = true;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::Id(int id) {
                this -> canId = id;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::MotorType(rev::CANSparkMax::MotorType type) {
                this -> motorType = type;
                return *this;
            }

            CANSparkMaxBuilder& CANSparkMaxBuilder::CurrentLimit(units::current::ampere_t limit) {
                this -> currentLimit = limit;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::IdleMode(rev::CANSparkMax::IdleMode mode) {
                this -> idleMode = mode;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::OpenLoopRampRate(units::time::second_t rate) {
                this -> openLoopRampRate = rate;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::ClosedLoopRampRate(units::time::second_t rate) {
                this -> closedLoopRampRate = rate;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::FollowOther(std::shared_ptr<rev::CANSparkMax> other, bool inverted) {
                this -> followOther = other;
                this -> reverseFollowTarget = inverted;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::FollowExternal(std::shared_ptr<rev::CANSparkMax::ExternalFollower> other, int id, bool inverted) {
                this -> followObj = other;
                this -> reverseFollowTarget = inverted;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::CANTimeout(units::time::millisecond_t timeout) {
                this -> canTimeout = timeout;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::SoftLimit(rev::CANSparkMax::SoftLimitDirection direction, double limit) {
                this -> softLimitDirection = direction;
                this -> softLimit = limit;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::VoltageCompensation(units::voltage::volt_t compensation) {
                this -> voltageCompensation = compensation;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::EnableVoltageCompensation() {
                this -> enableVoltageCompensation = true;
				return *this;
			}

            CANSparkMaxBuilder& CANSparkMaxBuilder::EnableSoftLimit() {
                this -> enableSoftLimit = true;
				return *this;
			}

            controllers::CANSparkMax CANSparkMaxBuilder::Build() {
                std::unique_ptr<rev::CANSparkMax> spark = std::make_unique<rev::CANSparkMax>(canId, motorType);

                spark -> SetSmartCurrentLimit(currentLimit.value());
                spark -> SetIdleMode(idleMode);

                spark -> SetOpenLoopRampRate(openLoopRampRate.value());
                spark -> SetClosedLoopRampRate(closedLoopRampRate.value());

                spark -> SetCANTimeout(canTimeout.value());
                spark -> SetSoftLimit(softLimitDirection, softLimit);

                spark -> EnableSoftLimit(softLimitDirection, enableSoftLimit);

                if (enableVoltageCompensation) {
                    spark -> EnableVoltageCompensation(voltageCompensation.value());
                }

                if (followOther != nullptr) {
                    spark -> Follow(*followOther.get(), reverseFollowTarget);
                } else if (followObj != nullptr) {
                    spark -> Follow(*followObj.get(), reverseFollowTarget);
                }

                controllers::CANSparkMax sparkController{std::move(spark)};
                sparkController.SetInversionState(isInverted);
                sparkController.SetSpeedOutputMultiplier(speedOutputMultiplier);
                sparkController.SetSpeedThreshold(speedLimitThreshold);

                return sparkController;
            }

        }

    }

}
