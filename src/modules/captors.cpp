#include "modules/captors.hpp"

float Captors::getTemperature() const {
    return this->temperature;
}
float Captors::getSolarFlux() const {
    return this->solarFlux;
}
float Captors::getRadiationLevel() const {
    return this->radiationLevel;
}

void Captors::emulate(const Vec3& satPosition, const Vec3& sunPosition, const Vec3& earthPosition) {
    const Vec3 ES = sunPosition - satPosition;
    const float distanceSun = ES.length();
    float solarFlux = 1.0f / (distanceSun * distanceSun);

    solarFlux = std::clamp(solarFlux, 0.0f, 1.0f);

    this->solarFlux = solarFlux;

    const Vec3 EE = satPosition - earthPosition;
    const float distanceEarth = EE.length();

    float radiation = distanceEarth / 100000.0f;
    radiation += ((float)rand() / (float)RAND_MAX) * 0.1f;
    this->radiationLevel = std::clamp(radiation, 0.0f, 1.0f);

    float temperature = 20.0f + solarFlux * 80.0f - radiation * 40.0f;
    this->temperature = temperature;
}

bool Captors::isOk() const {
    return true;
}