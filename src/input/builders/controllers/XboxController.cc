#include "XboxController.hh"

namespace ffrc {

    namespace builders {

        namespace input {

            XboxController::XboxController() {}

            XboxController* XboxController::Port(int port) {
                this -> port = port;
            	return this;
			}

            XboxController* XboxController::LeftXSensitivity(double value) {
                this -> leftXSensitivity = value;
            	return this;
			}

            XboxController* XboxController::LeftYSensitivity(double value) {
				this -> leftYSensitivity = value;
            	return this;
			}

            XboxController* XboxController::RightXSensitivity(double value) {
				this -> rightXSensitivity = value;
            	return this;
			}

            XboxController* XboxController::RightYSensitivity(double value) {
				this -> rightYSensitivity = value;
            	return this;
			}

            XboxController* XboxController::LeftTriggerSensitivity(double value) {
				this -> leftTriggerSensitivity = value;
            	return this;
			}

            XboxController* XboxController::RightTriggerSensitivity(double value) {
				this -> rightTriggerSensitivity = value;
            	return this;
			}

            XboxController* XboxController::MinRequiredLeftXValue(double value) {
				this -> minRequiredLeftXValue = value;
            	return this;
			}

            XboxController* XboxController::MinRequiredLeftYValue(double value) {
				this -> minRequiredLeftYValue = value;
            	return this;
			}

            XboxController* XboxController::MinRequiredRightXValue(double value) {
				this -> minRequiredRightXValue = value;
            	return this;
			}

            XboxController* XboxController::MinRequiredRightYValue(double value) {
				this -> minRequiredRightYValue = value;
            	return this;
			}

            XboxController* XboxController::MinRequiredLeftTriggerValue(double value) {
				this -> minRequiredLeftTriggerValue = value;
            	return this;
			}

            XboxController* XboxController::MinRequiredRightTriggerValue(double value) {
				this -> minRequiredRightTriggerValue = value;
            	return this;
			}

            XboxController* XboxController::LeftXInversionState(bool value) {
				this -> leftXInverted= value;
            	return this;
			}

            XboxController* XboxController::LeftYInversionState(bool value) {
				this -> leftYInverted = value;
            	return this;
			}

            XboxController* XboxController::RightXInversionState(bool value) {
				this -> rightXInverted = value;
            	return this;
			}

            XboxController* XboxController::RightYInversionState(bool value) {
				this -> rightYInverted = value;
            	return this;
			}

            XboxController* XboxController::LeftTriggerInversionState(bool value) {
				this -> leftTriggerInverted = value;
            	return this;
			}

            XboxController* XboxController::RightTriggerInversionState(bool value) {
				this -> rightTriggerInverted = value;
            	return this;
			}

            XboxController* XboxController::LeftTriggerOppositeOutputState(bool value) {
				this -> leftTriggerOppositeOutput = value;
            	return this;
			}

            XboxController* XboxController::RightTriggerOpppsiteOutputState(bool value) {
				this -> rightTriggerOpppsiteOutput = value;
            	return this;
			}

            XboxController* XboxController::LeftXThreshold(util::Threshold value) {
				this -> leftXThreshold = value;
            	return this;
			}

            XboxController* XboxController::LeftYThreshold(util::Threshold value) {
				this -> leftYThreshold = value;
            	return this;
			}

            XboxController* XboxController::RightXThreshold(util::Threshold value) {
				this -> rightXThreshold = value;
            	return this;
			}

            XboxController* XboxController::RightYThreshold(util::Threshold value) {
				this -> rightYThreshold = value;
            	return this;
			}

            XboxController* XboxController::LeftTriggerThreshold(util::Threshold value) {
				this -> leftTriggerThreshold = value;
            	return this;
			}

            XboxController* XboxController::RightTriggerThreshold(util::Threshold value) {
				this -> rightTriggerThreshold = value;
            	return this;
			}

            std::shared_ptr<devices::input::XboxController> XboxController::Build() {
                std::shared_ptr<devices::input::XboxController> controller = std::make_shared<devices::input::XboxController>(port);

                controller -> SetLeftXSensitivity(leftXSensitivity);
                controller -> SetLeftYSensitivity(leftYSensitivity);

                controller -> SetRightXSensitivity(rightXSensitivity);
                controller -> SetRightYSensitivity(rightYSensitivity);
                
                controller -> SetRightTriggerSensitivity(rightTriggerSensitivity);
                controller -> SetLeftTriggerSensitivity(leftTriggerSensitivity);

                controller -> SetLeftXMinRequirement(minRequiredLeftXValue);
                controller -> SetLeftYMinRequirement(minRequiredLeftYValue);

                controller -> SetRightXMinRequirement(minRequiredRightXValue);
                controller -> SetRightYMinRequirement(minRequiredRightYValue);

                controller -> SetLeftTriggerMinRequirement(minRequiredLeftTriggerValue);
                controller -> SetRightTriggerMinRequirement(minRequiredRightTriggerValue);

                controller -> SetLeftXInversionState(leftXInverted);
                controller -> SetLeftYInversionState(leftYInverted);

                controller -> SetRightXInversionState(rightXInverted);
                controller -> SetRightYInversionState(rightYInverted);

                controller -> SetLeftTriggerInversionState(leftTriggerInverted);
                controller -> SetRightTriggerInversionState(rightTriggerInverted);

                controller -> SetLeftTriggerOppositeOutputState(leftTriggerOppositeOutput);
                controller -> SetRightTriggerOppositeOutputState(rightTriggerOpppsiteOutput);

                controller -> SetLeftXThreshold(leftXThreshold);
                controller -> SetLeftYThreshold(leftYThreshold);

                controller -> SetRightXThreshold(rightXThreshold);
                controller -> SetRightYThreshold(rightYThreshold);

                controller -> SetLeftTriggerThreshold(leftTriggerThreshold);
                controller -> SetRightTriggerThreshold(rightTriggerThreshold);

                return controller;
            }

        }

    }

}
