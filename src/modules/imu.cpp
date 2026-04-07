#include "core/constants.hpp"
#include "modules/imu.hpp"
#include <cstdlib>
#include <cmath>

float IMU::getRotation() const {
    return this->rotation;
}
float IMU::getPitch() const {
    return this->pitch;
}
float IMU::getYaw() const {
    return this->yaw;
}
float IMU::getRoll() const {
    return this->roll;
}

void IMU::emulate(GPS gps, const double dt) {
    const Vec3 angularVelocity = gps.getOrbitalSpeed() / gps.getPosition().length();
    this->rotation += angularVelocity.length() * dt;

    this->pitch += angularVelocity.x * dt;
    this->yaw   += angularVelocity.y * dt;
    this->roll  += angularVelocity.z * dt;

    const float noise = ((float)rand() / (float)RAND_MAX - 0.5f) * 0.01f;

    this->pitch += noise;
    this->yaw   += noise;
    this->roll  += noise;
}


bool IMU::isOk() const {
    return true;
}