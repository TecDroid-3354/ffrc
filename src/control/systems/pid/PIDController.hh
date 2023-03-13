#pragma once

#include <frc/controller/PIDController.h>
#include <functional>
#include <float.h>

#include "util/limits/Threshold.hh"

namespace ffrc {

    namespace systems {

        namespace pid {

            class PIDController {
                public:
                    PIDController(std::unique_ptr<frc2::PIDController>);

                    void   SetPIDValues(double, double, double);
                    void   SetP(double);
                    void   SetI(double);
                    void   SetD(double);

                    void   SetSetpoint(double);
                    bool   IsAtSetpoint();

                    void   SetInputReadAction(std::function<double()>);
                    void   SetOutputFeedAction(std::function<void(double)>);

                    void   SetClampThreshold(util::Threshold);
                    double ClampInThreshold(double);

                    void   SetContinuousInputRange(util::Threshold);
                    void   EnableContinuousInputRange();
                    void   DisableContinuousInputRange();

                    void   SetTolerance(double);

                    void   Update();
                    void   FeedOutput();
                    void   UpdateAndFeed();

                    double GetLastOutput();

                private:
                    std::unique_ptr<frc2::PIDController> controller;
                    util::Threshold clampThreshold{DBL_MIN, DBL_MAX};
                    util::Threshold continuousInputRange{0.0, 1.0};

                    std::function<double()> onReadInput      = [] (             ) { return 0.0; };
                    std::function<void(double)> onFeedOutput = [] (double output) {             };

                    double output;
            };

        }

    }

}
