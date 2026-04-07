#pragma once
#include "math/vec3.hpp"

class Captors {
private:
    float temperature;      // K
    float solarFlux;        // W/m²
    float radiationLevel;   // W/m²
public:
    Captors():
        temperature(0),
        solarFlux(0),
        radiationLevel(0) {}
    float getTemperature() const;
    float getSolarFlux() const;
    float getRadiationLevel() const;
    bool isOk() const;
    void emulate(const Vec3& satPosition, const Vec3& sunPosition, const Vec3& earthPosition);
};