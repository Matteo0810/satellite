#include "core/utils.hpp"
#include "modules/controller.hpp"

void Controller::update(
    const GPS& gps,
    const IMU& imu,
    const Captors& captors,
    const PowerSystem& powerSystem
) {
    json payload;

    payload["timestamp"] = get_current_timestamp();

    payload["status"] = {
        {"gps", gps.isOk()},
        {"imu", imu.isOk()},
        {"captors", captors.isOk()},
        {"power", powerSystem.isOk()}
    };

    payload["position_valid"] = gps.isOk();
    if (gps.isOk()) {
        payload["position"] = {
            {"x", gps.getPosition().x},
            {"y", gps.getPosition().y},
            {"z", gps.getPosition().z}
        };

        payload["orbitalSpeed"] = {
            {"x", gps.getOrbitalSpeed().x},
            {"y", gps.getOrbitalSpeed().y},
            {"z", gps.getOrbitalSpeed().z}
        };
    }

    payload["imu_valid"] = imu.isOk();
    if (imu.isOk()) {
        payload["rotation"] = imu.getRotation();
        payload["pitch"] = imu.getPitch();
        payload["yaw"] = imu.getYaw();
        payload["roll"] = imu.getRoll();
    }

    payload["captors_valid"] = captors.isOk();
    if (captors.isOk()) {
        payload["temperature"] = captors.getTemperature();
        payload["solarFlux"] = captors.getSolarFlux();
    }

    payload["power_valid"] = powerSystem.isOk();
    if (powerSystem.isOk()) {
        payload["battery"] = powerSystem.getBattery();
    }

    this->telecommunications.send(payload.dump(), &gps, earth.position);
}