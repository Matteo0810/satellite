#include "modules/captors.hpp"
#include "modules/imu.hpp"
#include "modules/gps.hpp"
#include "modules/telecommunications.hpp"
#include "modules/power_system.hpp"

class Controller {
private:
    Telecommunications telecommunications;
public:
    Controller(
        Telecommunications telecommunications
    ): telecommunications(telecommunications) {}
    void update(
        const GPS& gps,
        const IMU& imu,
        const Captors& captors,
        const PowerSystem& powerSystem
    );
};