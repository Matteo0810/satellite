#include "core/logger.hpp"
#include "core/constants.hpp"

#include "simulation/celestal_body.hpp"

#include "modules/board_computer.hpp"
#include "modules/gps.hpp"
#include "modules/power_system.hpp"
#include "modules/telecommunications.hpp"
#include "modules/captors.hpp"
#include "modules/controller.hpp"
#include "modules/imu.hpp"

GPS gps;
IMU imu;
Telecommunications telecommunications;
PowerSystem power_system;
Captors captors;
BoardComputer board_computer(
    gps,
    imu,
    telecommunications,
    power_system,
    captors
);
Controller controller(telecommunications);

void simulationLoop() {
    Logger::log("Enabling simulation...", "Main", "INFO");

    while (true) {
        board_computer.emulate(DT);
        controller.update(gps, imu, captors, power_system);

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}