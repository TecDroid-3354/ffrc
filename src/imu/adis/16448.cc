#include "16448.hh"

namespace ffrc {

    namespace devices {

        namespace imu {

            ADIS16448IMU::ADIS16448IMU(std::unique_ptr<frc::ADIS16448_IMU> imu):
            imu(std::move(imu)) {}

            units::acceleration::meters_per_second_squared_t ADIS16448IMU::GetXAcceleration() {
                return imu -> GetAccelX();
            }

            units::acceleration::meters_per_second_squared_t ADIS16448IMU::GetYAcceleration() {
                return imu -> GetAccelY();
            }

            units::acceleration::meters_per_second_squared_t ADIS16448IMU::GetZAcceleration() {
                return imu -> GetAccelZ();
            }

            units::angle::degree_t ADIS16448IMU::GetXRotation() {
                return imu -> GetGyroAngleX() - xAngleResetComp;
            }

            units::angle::degree_t ADIS16448IMU::GetYRotation() {
                return imu -> GetGyroAngleY() - yAngleResetComp;
            }

            units::angle::degree_t ADIS16448IMU::GetZRotation() {
                return imu -> GetGyroAngleZ() - zAngleResetComp;
            }

            void ADIS16448IMU::ResetXRotation() {
                xAngleResetComp = imu -> GetGyroAngleX();
            }

            void ADIS16448IMU::ResetYRotation() {
                yAngleResetComp = imu -> GetGyroAngleY();
            }

            void ADIS16448IMU::ResetZRotation() {
                zAngleResetComp = imu -> GetGyroAngleZ();
            }

            units::angle::degree_t ADIS16448IMU::GetCompassRotation() {
                return imu -> GetAngle();

            }

            units::magnetic_field_strength::tesla_t ADIS16448IMU::GetXFieldStrength() {
                return imu -> GetMagneticFieldX();
            }

            units::magnetic_field_strength::tesla_t ADIS16448IMU::GetYFieldStrength() {
                return imu -> GetMagneticFieldY();
            }

            units::magnetic_field_strength::tesla_t ADIS16448IMU::GetZFieldStrength() {
                return imu -> GetMagneticFieldZ();
            }

            units::pressure::bar_t ADIS16448IMU::GetPressure() {
                return imu -> GetBarometricPressure();
            }

        }

    }

}
