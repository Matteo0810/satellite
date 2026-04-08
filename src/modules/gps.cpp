#include <cmath>
#include "core/constants.hpp"

#include "math/vec3.hpp"
#include "modules/gps.hpp"

Vec3 GPS::getPosition() const {
    return this->position;
}
Vec3 GPS::getOrbitalSpeed() const {
    return this->orbitalSpeed;
}
void GPS::emulate(const CelestialBody planet, const double dt) {
    Vec3 rVec = this->position - planet.position;

    double r2 = rVec.length2();
    if (r2 < 1e-12) return;

    double r = std::sqrt(r2);

    Vec3 radial = rVec / r;

    if (!this->initialized) {
        Vec3 tangent = Vec3(radial.z, 0.0, -radial.x).normalized();

        double v = std::sqrt(G * planet.mass / r);

        this->orbitalSpeed = tangent * v;
        this->initialized = true;
    }

    Vec3 acceleration = radial * (-(G * planet.mass) / r2);

    this->orbitalSpeed += acceleration * dt;
    this->position += this->orbitalSpeed * dt;
}

bool GPS::isOk() const {
    return true;
}