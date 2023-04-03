#include "PIDController.hh"

namespace ffrc {

    namespace systems {

        namespace pid {

            PIDController::PIDController(std::unique_ptr<frc2::PIDController> controller):
            controller{std::move(controller)} {}

            void PIDController::SetPIDValues(double p, double i, double d) {
                this -> controller -> SetP(p);
                this -> controller -> SetI(i);
                this -> controller -> SetD(d);
            }

            void PIDController::SetP(double value) {
                this -> controller -> SetP(value);
            }

            void PIDController::SetI(double value) {
                this -> controller -> SetI(value);
            }

            void PIDController::SetD(double value) {
                this -> controller -> SetD(value);
            }

            void PIDController::SetInputReadAction(std::function<double()> action) {
                this -> onReadInput = action;
            }

            void PIDController::SetSetpoint(double value) {
                this -> controller -> SetSetpoint(value);
            }

            bool PIDController::IsAtSetpoint() {
                return this -> controller -> AtSetpoint();
            }

            void PIDController::SetOutputFeedAction(std::function<void(double)> action) {
                this -> onFeedOutput = action;
            }

            void PIDController::SetClampThreshold(util::Threshold value) {
                this -> clampThreshold = value;
            }

            double PIDController::ClampInThreshold(double value) {
                return clampThreshold.Clamp(value);
            }

            void PIDController::SetContinuousInputRange(util::Threshold range) {
                this -> continuousInputRange = range;
            }

            void PIDController::EnableContinuousInputRange() {
                this -> controller -> EnableContinuousInput(continuousInputRange.lowerBound, continuousInputRange.upperBound);

            }

            void PIDController::DisableContinuousInputRange() {
                this -> controller -> DisableContinuousInput();
            }   

            void PIDController::SetTolerance(double value) {
                this -> controller -> SetTolerance(value);
            }

            void PIDController::Update() {
                output = clampThreshold.Clamp(controller -> Calculate(onReadInput()));
            }

            void PIDController::FeedOutput() {
                onFeedOutput(output);
            }

            void PIDController::UpdateAndFeed() {
                output = clampThreshold.Clamp(controller -> Calculate(onReadInput()));
                onFeedOutput(output);
            }

            double PIDController::GetLastOutput() {
               return this -> output;
            }

        }

    }

}
