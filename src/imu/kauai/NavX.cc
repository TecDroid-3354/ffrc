#pragma once

#include "NavX.hh"

namespace ffrc {

    namespace devices {

        namespace imu {

            NavX::NavX(std::unique_ptr<AHRS> imu):
            imu(std::move(imu)) {}

            units::acceleration::meters_per_second_squared_t NavX::GetXAcceleration() {
                return units::acceleration::meters_per_second_squared_t { imu -> GetWorldLinearAccelX() };
            }

            units::acceleration::meters_per_second_squared_t NavX::GetYAcceleration() {
                return units::acceleration::meters_per_second_squared_t { imu -> GetWorldLinearAccelY() };
            }

            units::acceleration::meters_per_second_squared_t NavX::GetZAcceleration() {
                return units::acceleration::meters_per_second_squared_t { imu -> GetWorldLinearAccelZ() };
            }

            units::velocity::meters_per_second_t NavX::GetXVelocity() {
                return units::velocity::meters_per_second_t { imu -> GetVelocityX() };
            }

            units::velocity::meters_per_second_t NavX::GetYVelocity() {
                return units::velocity::meters_per_second_t { imu -> GetVelocityY() };
            }

            units::velocity::meters_per_second_t NavX::GetZVelocity() {
                return units::velocity::meters_per_second_t { imu -> GetVelocityZ() };
            }

            units::length::meter_t NavX::GetXDisplacement() {
                return units::length::meter_t { imu -> GetDisplacementX() - xDisplacementResetComp };
            }

            units::length::meter_t NavX::GetYDisplacement() {
                return units::length::meter_t { imu -> GetDisplacementY() - yDisplacementResetComp };
            }

            units::length::meter_t NavX::GetZDisplacement() {
                return units::length::meter_t { imu -> GetDisplacementZ() - zDisplacementResetComp };
            }

            void NavX::ResetXDisplacement() {
                xDisplacementResetComp = GetXDisplacement();
            }

            void NavX::ResetYDisplacement() {
                yDisplacementResetComp = GetYDisplacement();
            }

            void NavX::ResetZDisplacement() {
                zDisplacementResetComp = GetZDisplacement();
            }

            void NavX::ResetDisplacement() {
                xDisplacementResetComp = 0_m;
                yDisplacementResetComp = 0_m;
                zDisplacementResetComp = 0_m;
                imu -> ResetDisplacement();
            }

            units::angle::degree_t NavX::GetXRotation() {
                return units::angle::degree_t { imu -> GetPitch() - xAngleResetComp };
            }

            units::angle::degree_t NavX::GetYRotation() {
                return units::angle::degree_t { imu -> GetRoll() - yAngleResetComp };
            }


            units::angle::degree_t NavX::GetZRotation() {
                return units::angle::degree_t { imu -> GetYaw() - zAngleResetComp };
            }

            void NavX::ResetXRotation() {
                xAngleResetComp = GetXRotation();
            }

            void NavX::ResetYRotation() {
                yAngleResetComp = GetYRotation();
            }

            void NavX::ResetZRotation() {
                imu -> Reset();
            }

            void NavX::ResetRotation() {
                ResetXRotation();
                ResetYRotation();
                ResetZRotation();
            }

            units::angle::degree_t NavX::GetCompassRotation() {
                return units::angle::degree_t { imu -> GetCompassHeading() };
            }

            units::magnetic_field_strength::tesla_t NavX::GetXFieldStrength() {
                return units::magnetic_field_strength::microtesla_t { imu -> GetRawMagX() };
            }

            units::magnetic_field_strength::tesla_t NavX::GetYFieldStrength() {
                return units::magnetic_field_strength::microtesla_t { imu -> GetRawMagY() };
            }

            units::magnetic_field_strength::tesla_t NavX::GetZFieldStrength() {
                return units::magnetic_field_strength::microtesla_t { imu -> GetRawMagZ() };
            }

            units::pressure::bar_t NavX::GetPressure() {
                return units::pressure::bar_t { imu -> GetBarometricPressure() * 1000 };
            }

        }

    }

}
