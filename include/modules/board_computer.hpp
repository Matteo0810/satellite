#include "modules/gps.hpp"
#include "modules/power_system.hpp"
#include "modules/telecommunications.hpp"
#include "modules/captors.hpp"
#include "modules/imu.hpp"

class BoardComputer {
private:   
    GPS& gps;
    IMU& imu;
    Telecommunications& telecommunications;
    PowerSystem& powerSystem;
    Captors& captors;
public:
    BoardComputer(
        GPS& gps,
        IMU& imu,
        Telecommunications& telecommunications,
        PowerSystem& powerSystem,
        Captors& captors
    ):
        gps(gps),
        imu(imu),
        telecommunications(telecommunications),
        powerSystem(powerSystem),
        captors(captors) {}
    void emulate(double dt);
};