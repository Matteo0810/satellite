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
    const Vec3 S = this->getPosition();
    const Vec3 E = planet.position;
    const Vec3 ES = E - S;

    const double r = ES.length();
    const Vec3 direction = ES.normalized();

    const double M = planet.mass;

    const Vec3 a = direction * ((G*M) / (r * r));

    this->orbitalSpeed += a * dt;
    this->position += this->orbitalSpeed * dt;
}

bool GPS::isOk() const {
    return true;
}