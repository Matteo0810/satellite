#include <cmath>
#include "core/constants.h"

#include "math/vec3.h"
#include "modules/gps.h"

Vec3 GPS::getPosition() {
    return this->position;
}
Vec3 GPS::getOrbitalSpeed() {
    return this->orbitalSpeed;
}
void GPS::emulate(Planet planet) {
    const Vec3 S = this->getPosition();
    const Vec3 E = planet.position;
    const Vec3 ES = E - S;

    const float r = ES.length();
    const Vec3 direction = ES.normalized();

    const float M = planet.mass;

    const Vec3 a = direction * ((G*M) / (r * r));

    this->orbitalSpeed += a * dt;
    this->position += this->orbitalSpeed * dt;

    this->position.print();
    this->orbitalSpeed.print();
}   