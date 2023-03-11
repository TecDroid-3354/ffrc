#include "CANSparkMax.hh"

namespace ffrc {

    namespace builders {

        namespace motorcontrollers {

            CANSparkMax* CANSparkMax::SpeedLimitThreshold(util::Threshold threshold) {
                this -> speedLimitThreshold = threshold;
                return this;
            }

            CANSparkMax* CANSparkMax::SpeedOutputMultiplier(double multiplier) {
                this -> speedOutputMultiplier = multiplier;
                return this;
            }

            CANSparkMax* CANSparkMax::Invert() {
                this -> isInverted = true;
                return this;
            }

            CANSparkMax* CANSparkMax::Id(int id) {
                this -> canId = id;
                return this;
            }

            CANSparkMax* CANSparkMax::MotorType(rev::CANSparkMax::MotorType type) {
                this -> motorType = type;
                return this;
            }

            CANSparkMax* CANSparkMax::CurrentLimit(units::current::ampere_t limit) {
                this -> currentLimit = limit;
				return this;
			}

            CANSparkMax* CANSparkMax::IdleMode(rev::CANSparkMax::IdleMode mode) {
                this -> idleMode = mode;
				return this;
			}

            CANSparkMax* CANSparkMax::OpenLoopRampRate(units::time::second_t rate) {
                this -> openLoopRampRate = rate;
				return this;
			}

            CANSparkMax* CANSparkMax::ClosedLoopRampRate(units::time::second_t rate) {
                this -> closedLoopRampRate = rate;
				return this;
			}

            CANSparkMax* CANSparkMax::FollowOther(std::shared_ptr<rev::CANSparkMax> other, bool inverted) {
                this -> followOther = other;
                this -> reverseFollowTarget = inverted;
				return this;
			}

            CANSparkMax* CANSparkMax::FollowExternal(std::shared_ptr<rev::CANSparkMax::ExternalFollower> other, int id, bool inverted) {
                this -> followObj = other;
                this -> reverseFollowTarget = inverted;
				return this;
			}

            CANSparkMax* CANSparkMax::CANTimeout(units::time::millisecond_t timeout) {
                this -> canTimeout = timeout;
				return this;
			}

            CANSparkMax* CANSparkMax::SoftLimit(rev::CANSparkMax::SoftLimitDirection direction, double limit) {
                this -> softLimitDirection = direction;
                this -> softLimit = limit;
				return this;
			}

            CANSparkMax* CANSparkMax::VoltageCompensation(units::voltage::volt_t compensation) {
                this -> voltageCompensation = compensation;
				return this;
			}

            CANSparkMax* CANSparkMax::EnableVoltageCompensation() {
                this -> enableVoltageCompensation = true;
				return this;
			}

            CANSparkMax* CANSparkMax::EnableSoftLimit() {
                this -> enableSoftLimit = true;
				return this;
			}

            std::shared_ptr<devices::motorcontrollers::CANSparkMax> CANSparkMax::Build() {
                std::unique_ptr<rev::CANSparkMax> spark = std::make_unique<rev::CANSparkMax>(canId, motorType);

                spark -> SetSmartCurrentLimit(currentLimit.value());
                spark -> SetIdleMode(idleMode);

                spark -> SetOpenLoopRampRate(openLoopRampRate.value());
                spark -> SetClosedLoopRampRate(closedLoopRampRate.value());

                spark -> SetCANTimeout(canTimeout.value());
                spark -> SetSoftLimit(softLimitDirection, softLimit);

                spark -> EnableSoftLimit(softLimitDirection, enableSoftLimit);

                spark -> SetInverted(isInverted);

                if (enableVoltageCompensation) {
                    spark -> EnableVoltageCompensation(voltageCompensation.value());
                }

                if (followOther.get() != nullptr) {
                    spark -> Follow(*followOther.get(), reverseFollowTarget);

                } else if (followObj.get() != nullptr) {
                    spark -> Follow(*followObj.get(), reverseFollowTarget);

                }

                std::shared_ptr<devices::motorcontrollers::CANSparkMax> sparkController =
                    std::make_shared<devices::motorcontrollers::CANSparkMax>(std::move(spark));

                sparkController -> SetSpeedOutputMultiplier(speedOutputMultiplier);
                sparkController -> SetSpeedThreshold(speedLimitThreshold);

                return sparkController;
            }

        }

    }

}
