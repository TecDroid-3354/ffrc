#pragma once

#include <optional>

#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>

#include "RobotContainer.hh"

#include "motorcontrollers/builders/rev/CANSparkMax.hh"
#include "encoders/builders/rev/SparkMaxRelativeEncoder.hh"

class Robot : public frc::TimedRobot {
    friend RobotContainer;
  
    public:
        void RobotInit() override;
        void RobotPeriodic() override;

        void DisabledInit() override;
        void DisabledPeriodic() override;
        void DisabledExit() override;

        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void AutonomousExit() override;

        void TeleopInit() override;
        void TeleopPeriodic() override;
        void TeleopExit() override;

        void TestInit() override;
        void TestPeriodic() override;
        void TestExit() override;

    private:
        std::optional<frc2::CommandPtr> m_autonomousCommand;

        RobotContainer m_container;

};
