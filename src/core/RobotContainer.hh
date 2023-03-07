#pragma once

#include <frc2/command/CommandPtr.h>

#include "motorcontrollers/builders/REV/CANSparkMax.hh"

class RobotContainer {
    public:
        RobotContainer();

        frc2::CommandPtr GetAutonomousCommand();

    private:
        void ConfigureBindings();
        ffrc::motorcontrol::controllers::CANSparkMax spark =
            ffrc::motorcontrol::builders::CANSparkMaxBuilder()
            .MotorType(rev::CANSparkMax::MotorType::kBrushed)
            .Id(1)
            .Invert()
            .SpeedOutputMultiplier(0.5)
            .Build();
};
