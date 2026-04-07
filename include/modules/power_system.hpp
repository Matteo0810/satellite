#pragma once

class PowerSystem {
private:
    float battery;
    float maxBattery;
    float solarProduction;
public:
    PowerSystem() : 
        battery(100),
        maxBattery(100),
        solarProduction(100) {}
    float getBattery() const;
    bool isOk() const;
    void emulate(const double dt);
};