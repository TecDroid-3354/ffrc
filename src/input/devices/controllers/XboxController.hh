#pragma once

#include "util/limits/Threshold.hh"
#include <frc/XboxController.h>

namespace ffrc {

    namespace devices {
        
        namespace input {

            class XboxController {
                public:
                    XboxController(unsigned int port);

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
