#pragma once
#include "math/vec3.hpp"
#include "simulation/celestal_body.hpp"

class GPS {
private:
    Vec3 position;
    Vec3 orbitalSpeed;

public:
    GPS():
        position({ 36000.0f, 0.0, 1000.0 }),
        orbitalSpeed(7.8) {} // km/s
    Vec3 getPosition() const;
    Vec3 getOrbitalSpeed() const;

    bool isOk() const;
    
    void emulate(const CelestialBody planet, const double dt);
};