#pragma once

#include "input/devices/controllers/XboxController.hh"

#include <memory>
#include <frc/XboxController.h>

namespace ffrc {
    
    namespace builders {

        namespace input {

            class XboxController {
                public: 
                    XboxController();

                    XboxController* Port(int);

                    XboxController* LeftXSensitivity(double);
                    XboxController* LeftYSensitivity(double);
                    XboxController* RightXSensitivity(double);
                    XboxController* RightYSensitivity(double);

                    XboxController* LeftTriggerSensitivity(double);
                    XboxController* RightTriggerSensitivity(double);

                    XboxController* MinRequiredLeftXValue(double);
                    XboxController* MinRequiredLeftYValue(double);
                    XboxController* MinRequiredRightXValue(double); 
                    XboxController* MinRequiredRightYValue(double);

                    XboxController* MinRequiredLeftTriggerValue(double);
                    XboxController* MinRequiredRightTriggerValue(double);

                    XboxController* LeftXInversionState(bool);
                    XboxController* LeftYInversionState(bool);

                    XboxController* RightXInversionState(bool);
                    XboxController* RightYInversionState(bool);

                    XboxController* LeftTriggerInversionState(bool);
                    XboxController* RightTriggerInversionState(bool);

                    XboxController* LeftTriggerOppositeOutputState(bool);
                    XboxController* RightTriggerOpppsiteOutputState(bool);

                    XboxController* LeftXThreshold(util::Threshold);
                    XboxController* LeftYThreshold(util::Threshold);
                    XboxController* RightXThreshold(util::Threshold);
                    XboxController* RightYThreshold(util::Threshold);

                    XboxController* LeftTriggerThreshold(util::Threshold);
                    XboxController* RightTriggerThreshold(util::Threshold);

                    devices::input::XboxController Build();

                private:
                    int port = 0;

                    double leftXSensitivity  = 1.0;
                    double leftYSensitivity  = 1.0;
                    double rightXSensitivity = 1.0;
                    double rightYSensitivity = 1.0;

                    double leftTriggerSensitivity = 1.0;
                    double rightTriggerSensitivity = 1.0;

                    double minRequiredLeftXValue = 0.0;
                    double minRequiredLeftYValue = 0.0;
                    double minRequiredRightXValue = 0.0; 
                    double minRequiredRightYValue = 0.0;

                    double minRequiredLeftTriggerValue  = 0.0;
                    double minRequiredRightTriggerValue = 0.0;

                    bool leftXInverted = false;
                    bool leftYInverted = false;

                    bool rightXInverted = false;
                    bool rightYInverted = false;

                    bool leftTriggerInverted  = false;
                    bool rightTriggerInverted = false;

                    bool leftTriggerOppositeOutput  = false;
                    bool rightTriggerOpppsiteOutput = false;

                    util::Threshold  leftXThreshold{-1.0, 1.0};
                    util::Threshold  leftYThreshold{-1.0, 1.0};
                    util::Threshold rightXThreshold{-1.0, 1.0};
                    util::Threshold rightYThreshold{-1.0, 1.0};

                    util::Threshold leftTriggerThreshold{-1.0, 1.0};
                    util::Threshold rightTriggerThreshold{-1.0, 1.0};
            };
        }
    }
}
