#pragma once

#include <frc2/command/CommandPtr.h>

#include "motorcontrollers/builders/REV/CANSparkMax.hh"
#include "motorcontrollers/builders/CTRE/VictorSPX.hh"

class RobotContainer {
    public:
        RobotContainer();

        frc2::CommandPtr GetAutonomousCommand();

    private:
        void ConfigureBindings();

};
