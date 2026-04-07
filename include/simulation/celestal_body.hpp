#pragma once
#include "math/vec3.hpp"

struct CelestialBody {
    Vec3 position;
    double mass;
    double rayon;
};

extern CelestialBody earth;
extern CelestialBody sun;