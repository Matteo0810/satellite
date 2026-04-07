#include <iostream>
#include <algorithm>

#include "core/constants.hpp"
#include "modules/power_system.hpp"

float PowerSystem::getBattery() const {
    return this->battery;
}
void PowerSystem::emulate(const double dt) {
    const float baseSolar = this->solarProduction;
    const float exposure = 1.0f;

    const float production = baseSolar * exposure;

    const float gpsConsumption = 2.0f;
    const float telecomConsumption = 10.0f;
    const float systemConsumption = 5.0f;

    const float consumption = gpsConsumption + telecomConsumption + systemConsumption;

    this->battery += (production - consumption) * dt;
    this->battery = std::clamp(this->battery, 0.0f, this->maxBattery);
}


bool PowerSystem::isOk() const {
    return this->battery >= 0 && this->battery <= this->maxBattery;
}