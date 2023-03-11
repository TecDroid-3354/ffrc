#include "XboxController.hh"

namespace ffrc {
    
    namespace devices {

        namespace input {

            XboxController::XboxController(unsigned int port):
            controller{port} {}

            double XboxController::LeftXAxis() {
                double controllerOutput = controller.GetLeftX() * leftXSensitivity;
                double value = controllerOutput * (std::abs(controllerOutput) >= minRequiredLeftXValue);

                return util::ClampValueInThreshold(leftXThreshold,
                    value * leftXInversionMultiplier
                );
            }

            double XboxController::LeftYAxis() {
                double controllerOutput = controller.GetLeftY() * leftYSensitivity;
                double value = controllerOutput * (std::abs(controllerOutput) >= minRequiredLeftYValue);

                return util::ClampValueInThreshold(leftYThreshold,
                    value * leftYInversionMultiplier 
                );
            }

            double XboxController::RightXAxis() {
                double controllerOutput = controller.GetRightX() * rightXSensitivity;
                double value = controllerOutput * (std::abs(controllerOutput) >= minRequiredRightXValue);

                return util::ClampValueInThreshold(rightXThreshold,
                    value * rightXInversionMultiplier
                );
            }

            double XboxController::RightYAxis() {
                double controllerOutput = controller.GetRightY() * rightYSensitivity;
                double value = controllerOutput * (std::abs(controllerOutput) >= minRequiredRightYValue);

                return util::ClampValueInThreshold(rightYThreshold,
                    value * rightYInversionMultiplier
                );
            }

            double XboxController::LeftTriggerAxis() {
                double controllerOutput = controller.GetLeftTriggerAxis() * leftTriggerSensitivity;
                double value = controllerOutput * (std::abs(controllerOutput) >= minRequiredLeftTriggerValue);

                return util::ClampValueInThreshold(leftTriggerThreshold,
                    std::abs(value - leftTriggerOppositeOutput) * leftTriggerInversionMultiplier
                );
            }

            double XboxController::RightTriggerAxis() {
                double controllerOutput = controller.GetRightTriggerAxis() * rightTriggerSensitivity;
                double value = controllerOutput * (std::abs(controllerOutput) >= minRequiredRightTriggerValue);

                return util::ClampValueInThreshold(rightTriggerThreshold,
                    std::abs(value - rightTriggerOpppsiteOutput) * rightTriggerInversionMultiplier
                );
            }

            double XboxController::GetTriggerDifference(bool leftIsPositive) {
                return (
                    (RightTriggerAxis() * (leftIsPositive ? -1 : 1)) + //
                    ( LeftTriggerAxis() * (leftIsPositive ? 1 : -1))   //
                );
            }

            bool XboxController::XButtonHeld() {
                return controller.GetXButtonPressed();
            }

            bool XboxController::XButtonReleased() {
                return controller.GetXButtonReleased();
            }

            bool XboxController::YButtonHeld() {
                return controller.GetYButtonPressed();
            }

            bool XboxController::YButtonReleased() {
                return controller.GetYButtonReleased();
            }

            bool XboxController::AButtonHeld() {
                return controller.GetAButtonPressed();
            }

            bool XboxController::AButtonReleased() {
                return controller.GetAButtonReleased();
            }

            bool XboxController::BButtonHeld() {
                return controller.GetBButtonPressed();
            }

            bool XboxController::BButtonReleased() {
                return controller.GetBButtonReleased();
            }

            bool XboxController::LeftBumperHeld() {
                return controller.GetLeftBumperPressed();
            }

            bool XboxController::LeftBumperReleased() {
                return controller.GetLeftBumperReleased();
            }

            bool XboxController::RightBumperHeld() {
                return controller.GetRightBumperPressed();
            }

            bool XboxController::RightBumperReleased() {
                return controller.GetRightBumperReleased();
            }

            bool XboxController::LeftStickButtonHeld() {
                return controller.GetLeftStickButtonPressed();
            }

            bool XboxController::LeftStickButtonReleased() {
                return controller.GetLeftStickButtonReleased();
            }

            bool XboxController::RightStickButtonHeld() {
                return controller.GetRightStickButtonPressed();
            }

            bool XboxController::RightStickButtonReleased() {
                return controller.GetRightStickButtonReleased();
            }

            bool XboxController::BackButtonHeld() {
                return controller.GetBackButtonPressed();
            }

            bool XboxController::BackButtonReleased() {
                return controller.GetBackButtonReleased();

            }

            bool XboxController::StartButtonHeld() {
                return controller.GetStartButtonPressed();
            }

            bool XboxController::StartButtonReleased() {
                return controller.GetStartButtonReleased();
            }

            int XboxController::GetPov() {
                return controller.GetPOV();
            }

            void XboxController::SetLeftXSensitivity(double value) {
                this -> leftXSensitivity = value;
            }

            void XboxController::SetLeftYSensitivity(double value) {
                this -> leftYSensitivity = value;
            }

            void XboxController::SetRightXSensitivity(double value) {
                this -> rightXSensitivity = value;
            }

            void XboxController::SetRightYSensitivity(double value) {
                this -> rightYSensitivity = value;
            }
            
            void XboxController::SetRightTriggerSensitivity(double value) {
                this -> rightTriggerSensitivity = value;
            }

            void XboxController::SetLeftTriggerSensitivity(double value) {
                this -> leftTriggerSensitivity = value;
            }

            void XboxController::SetLeftXMinRequirement(double value) {
                this -> minRequiredLeftXValue = value;
            }

            void XboxController::SetLeftYMinRequirement(double value) {
                this -> minRequiredLeftYValue = value;
            }

            void XboxController::SetRightXMinRequirement(double value) {
                this -> minRequiredRightXValue = value;
            }

            void XboxController::SetRightYMinRequirement(double value) {
                this -> minRequiredRightYValue = value;
            }

            void XboxController::SetLeftTriggerMinRequirement(double value) {
                this -> minRequiredLeftTriggerValue = value;
            }

            void XboxController::SetRightTriggerMinRequirement(double value) {
                this -> minRequiredRightTriggerValue = value;
            }

            void XboxController::SetLeftXInversionState(bool value) {
                this -> leftXInversionMultiplier = value - !value;
            }

            void XboxController::SetLeftYInversionState(bool value) {
                this -> leftYInversionMultiplier = value - !value;
            }

            void XboxController::SetRightXInversionState(bool value) {
                this -> rightXInversionMultiplier = value - !value;
            }

            void XboxController::SetRightYInversionState(bool value) {
                this -> rightYInversionMultiplier = value - !value;
            }

            void XboxController::SetLeftTriggerInversionState(bool value) {
                this -> leftTriggerInversionMultiplier = value - !value;
            }

            void XboxController::SetRightTriggerInversionState(bool value) {
                this -> rightTriggerInversionMultiplier = value - !value;
            }

            void XboxController::SetLeftTriggerOppositeOutputState(bool value) {
                this -> leftTriggerOppositeOutput = value;
            }

            void XboxController::SetRightTriggerOppositeOutputState(bool value) {
                this -> rightTriggerOpppsiteOutput = value;
            }

            void XboxController::SetLeftXThreshold(util::Threshold threshold) {
                this -> leftXThreshold = threshold;
            }

            void XboxController::SetLeftYThreshold(util::Threshold threshold) {
                this -> leftYThreshold = threshold;
            }

            void XboxController::SetLeftAxisThresholds(util::Threshold threshold) {
                leftXThreshold = threshold;
                leftYThreshold = threshold;
            }

            void XboxController::SetRightXThreshold(util::Threshold threshold) {
                this -> rightXThreshold = threshold;
            }

            void XboxController::SetRightYThreshold(util::Threshold threshold) {
                this -> rightYThreshold = threshold;
            }

            void XboxController::SetRightAxisThresholds(util::Threshold threshold) {
                rightXThreshold = threshold;
                rightYThreshold = threshold;
            }

            void XboxController::SetLeftTriggerThreshold(util::Threshold threshold) {
                this -> leftTriggerThreshold = threshold;
            }

            void XboxController::SetRightTriggerThreshold(util::Threshold threshold) {
                this -> rightTriggerThreshold = threshold;
            }

            void XboxController::SetTriggerThresholds(util::Threshold threshold) {
                leftTriggerThreshold  = threshold;
                rightTriggerThreshold = threshold;
            }

        }
    }
}