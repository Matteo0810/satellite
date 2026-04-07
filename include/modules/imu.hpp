#pragma once
#include "math/vec3.hpp"
#include "modules/gps.hpp"

class IMU {
private:
    float rotation;
    float pitch;
    float yaw;
    float roll;
public:
    IMU():
        rotation(0),
        pitch(0),
        yaw(0),
        roll(0) {}
    float getRotation() const;
    float getPitch() const;
    float getYaw() const;
    float getRoll() const;
    bool isOk() const;
    void emulate(GPS gps, const double dt);
};