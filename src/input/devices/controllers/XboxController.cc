#include "XboxController.hh"

namespace ffrc {
    
    namespace devices {

        namespace input {

            XboxController::XboxController(unsigned int port):
            controller{port} {}

            double XboxController::LeftXAxis() {
                return util::ClampValueInThreshold(leftXThreshold, controller.GetLeftX());
            }

            double XboxController::LeftYAxis() {
                return util::ClampValueInThreshold(leftYThreshold, controller.GetLeftY());
            }

            double XboxController::RightXAxis() {
                return util::ClampValueInThreshold(rightXThreshold, controller.GetRightX());
            }

            double XboxController::RightYAxis() {
                return util::ClampValueInThreshold(rightYThreshold, controller.GetRightY());
            }

            double XboxController::LeftTriggerAxis() {
                return util::ClampValueInThreshold(leftTriggerThreshold, controller.GetLeftTriggerAxis());
            }

            double XboxController::RightTriggerAxis() {
                return util::ClampValueInThreshold(rightTriggerThreshold, controller.GetRightTriggerAxis());
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