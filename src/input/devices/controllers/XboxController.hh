#pragma once

#include "util/limits/Threshold.hh"
#include <frc/XboxController.h>

namespace ffrc {

    namespace devices {
        
        namespace input {

            class XboxController {
                public:
                    XboxController(int port);

                    double LeftXAxis();
                    double LeftYAxis();

                    double RightXAxis();
                    double RightYAxis();

                    double LeftTriggerAxis();
                    double RightTriggerAxis();

                    double GetTriggerDifference(bool = false);

                    bool   XButtonHeld();
                    bool   XButtonReleased();

                    bool   YButtonHeld();
                    bool   YButtonReleased();

                    bool   AButtonHeld();
                    bool   AButtonReleased();

                    bool   BButtonHeld();
                    bool   BButtonReleased();

                    bool   LeftBumperHeld();
                    bool   LeftBumperReleased();

                    bool   RightBumperHeld();
                    bool   RightBumperReleased();

                    bool   LeftStickButtonHeld();
                    bool   LeftStickButtonReleased();

                    bool   RightStickButtonHeld();
                    bool   RightStickButtonReleased();

                    bool   BackButtonHeld();
                    bool   BackButtonReleased();

                    bool   StartButtonHeld();
                    bool   StartButtonReleased();

                    int    GetPov();

                    void   SetLeftXSensitivity(double);
                    void   SetLeftYSensitivity(double);

                    void   SetRightXSensitivity(double);
                    void   SetRightYSensitivity(double);
                    
                    void   SetRightTriggerSensitivity(double);
                    void   SetLeftTriggerSensitivity(double);

                    void   SetLeftXMinRequirement(double);
                    void   SetLeftYMinRequirement(double);

                    void   SetRightXMinRequirement(double);
                    void   SetRightYMinRequirement(double);

                    void   SetRightTriggerMinRequirement(double);
                    void   SetLeftTriggerMinRequirement(double);

                    void   SetLeftXInversionState(bool);
                    void   SetLeftYInversionState(bool);

                    void   SetRightXInversionState(bool);
                    void   SetRightYInversionState(bool);

                    void   SetRightTriggerInversionState(bool);
                    void   SetLeftTriggerInversionState(bool);

                    void   SetLeftTriggerOppositeOutputState(bool);
                    void   SetRightTriggerOppositeOutputState(bool);

                    void   SetLeftXThreshold(util::Threshold);
                    void   SetLeftYThreshold(util::Threshold);
                    void   SetLeftAxisThresholds(util::Threshold x);

                    void   SetRightXThreshold(util::Threshold);
                    void   SetRightYThreshold(util::Threshold);
                    void   SetRightAxisThresholds(util::Threshold);

                    void   SetLeftTriggerThreshold(util::Threshold);
                    void   SetRightTriggerThreshold(util::Threshold);
                    void   SetTriggerThresholds(util::Threshold);

                private:
                    frc::XboxController controller;

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

                    char leftXInversionMultiplier = 1;
                    char leftYInversionMultiplier = 1;

                    char rightXInversionMultiplier = 1;
                    char rightYInversionMultiplier = 1;

                    char rightTriggerInversionMultiplier = 1;
                    char leftTriggerInversionMultiplier  = 1;

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
