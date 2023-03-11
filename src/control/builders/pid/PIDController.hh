#pragma once

#include "control/systems/pid/PIDController.hh"

namespace ffrc {
    
    namespace builders {

        namespace pid {

            class PIDController {
                public:
                    PIDController* P(double);
                    PIDController* I(double);
                    PIDController* D(double);

                    PIDController* ClampThreshold(util::Threshold);
                    PIDController* ContinuousOutputRange(util::Threshold);
                    PIDController* WithContinuousOutputRange();

                    PIDController* OnReadInput(std::function<double()>);
                    PIDController* OnFeedOutput(std::function<void(double)>);

                    std::shared_ptr<systems::pid::PIDController> Build();

                private:
                    double p = 0.0,
                           i = 0.0,
                           d = 0.0;

                    bool enableCIR = false;

                    std::function<void(double)> onFeedOutput = [] (double output) {             };
                    std::function<double()> onReadInput =      [] (             ) { return 0.0; };

                    util::Threshold clampThreshold{-1.0, 1.0};
                    util::Threshold CIR{0.0, 1.0};


            };

        }

    }

}