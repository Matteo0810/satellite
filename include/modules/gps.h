#pragma once
#include "math/vec3.h"
#include "simulation/planet.h"

class GPS {
private:
    Vec3 position;
    Vec3 orbitalSpeed;

public:
    GPS() {
        position = { 36000.0f, 0.0f, 0.0f };
        orbitalSpeed = 7.8f; // km/s
    }

    Vec3 getPosition();
    Vec3 getOrbitalSpeed();
    
    void emulate(Planet planet);
};