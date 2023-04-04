#pragma once

#include "sensors/devices/Accelerometer.hh"
#include "sensors/devices/Speedometer.hh"
#include "sensors/devices/PositionSensor.hh"
#include "sensors/devices/Magnetometer.hh"
#include "sensors/devices/Barometer.hh"
#include "sensors/devices/Gyroscope.hh"

#include <AHRS.h>

namespace ffrc {

    namespace devices {

        namespace imu {

            class NavX: 
                sensors::Accelerometer,
                sensors::Speedometer,
                sensors::PositionSensor,
                sensors::Gyroscope,
                sensors::Magnetometer,
                sensors::Barometer {
                public:

                    NavX(std::unique_ptr<AHRS>);

                    units::acceleration::meters_per_second_squared_t GetXAcceleration() override;
                    units::acceleration::meters_per_second_squared_t GetYAcceleration() override;
                    units::acceleration::meters_per_second_squared_t GetZAcceleration() override;

                    units::velocity::meters_per_second_t GetXVelocity() override;
                    units::velocity::meters_per_second_t GetYVelocity() override;
                    units::velocity::meters_per_second_t GetZVelocity() override;

                    units::length::meter_t GetXDisplacement() override;
                    units::length::meter_t GetYDisplacement() override;
                    units::length::meter_t GetZDisplacement() override;

                    void ResetXDisplacement() override;
                    void ResetYDisplacement() override;
                    void ResetZDisplacement() override;
                    void ResetDisplacement()  override;

                    units::angle::degree_t GetXRotation() override;
                    units::angle::degree_t GetYRotation() override;
                    units::angle::degree_t GetZRotation() override;

                    void ResetXRotation() override;
                    void ResetYRotation() override;
                    void ResetZRotation() override;
                    void ResetRotation()  override;

                    units::angle::degree_t GetCompassRotation() override;
                    units::magnetic_field_strength::tesla_t GetXFieldStrength() override;
                    units::magnetic_field_strength::tesla_t GetYFieldStrength() override;
                    units::magnetic_field_strength::tesla_t GetZFieldStrength() override;

                    units::pressure::bar_t GetPressure() override;

                private:

                    std::unique_ptr<AHRS> imu;

                    units::angle::degree_t xAngleResetComp = 0.0_deg;
                    units::angle::degree_t yAngleResetComp = 0.0_deg;
                    units::angle::degree_t zAngleResetComp = 0.0_deg;

                    units::length::meter_t xDisplacementResetComp = 0.0_m;
                    units::length::meter_t yDisplacementResetComp = 0.0_m;
                    units::length::meter_t zDisplacementResetComp = 0.0_m;

            };

        }

    }

}
