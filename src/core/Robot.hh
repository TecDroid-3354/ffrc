#pragma once

#include <optional>

#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>

#include "RobotContainer.hh"

#include "motorcontrollers/builders/REV/CANSparkMax.hh"
#include "encoders/builders/REV/SparkMaxRelativeEncoder.hh"

class Robot : public frc::TimedRobot {
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

  std::shared_ptr<ffrc::devices::motorcontrollers::CANSparkMax> controller =
    ffrc::builders::motorcontrollers::CANSparkMax()
    .Id(3)
    ->Build();

  std::shared_ptr<ffrc::devices::encoders::SparkMaxRelativeEncoder> encoder =
    ffrc::builders::encoders::SparkMaxRelativeEncoder(controller)
    .Build();

  RobotContainer m_container;
};
