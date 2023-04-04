#pragma once

#include "sensors/devices/Accelerometer.hh"
#include "sensors/devices/Magnetometer.hh"
#include "sensors/devices/Barometer.hh"
#include "sensors/devices/Gyroscope.hh"

#include <frc/ADIS16448_IMU.h>

namespace ffrc {

    namespace devices {

        namespace imu {

            class ADIS16448IMU: 
                sensors::Barometer,
                sensors::Accelerometer,
                sensors::Magnetometer,
                sensors::Gyroscope {
                public:

                    ADIS16448IMU(std::unique_ptr<frc::ADIS16448_IMU>);

                    units::acceleration::meters_per_second_squared_t GetXAcceleration() override;
                    units::acceleration::meters_per_second_squared_t GetYAcceleration() override;
                    units::acceleration::meters_per_second_squared_t GetZAcceleration() override;

                    units::angle::degree_t GetXRotation() override;
                    units::angle::degree_t GetYRotation() override;
                    units::angle::degree_t GetZRotation() override;

                    void ResetXRotation() override;
                    void ResetYRotation() override;
                    void ResetZRotation() override;

                    units::angle::degree_t GetCompassRotation() override;
                    units::magnetic_field_strength::tesla_t GetXFieldStrength() override;
                    units::magnetic_field_strength::tesla_t GetYFieldStrength() override;
                    units::magnetic_field_strength::tesla_t GetZFieldStrength() override;

                    units::pressure::bar_t GetPressure() override;

                private:

                    std::unique_ptr<frc::ADIS16448_IMU> imu;

                    units::angle::degree_t xAngleResetComp = 0.0_deg;
                    units::angle::degree_t yAngleResetComp = 0.0_deg;
                    units::angle::degree_t zAngleResetComp = 0.0_deg;

            };

        }

    }

}
