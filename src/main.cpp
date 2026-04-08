#include <iostream>
#include "core/logger.hpp"

#include "simulation/celestal_body.hpp"

#include "modules/board_computer.hpp"
#include "modules/gps.hpp"
#include "modules/power_system.hpp"
#include "modules/telecommunications.hpp"
#include "modules/captors.hpp"
#include "modules/controller.hpp"
#include "modules/imu.hpp"

bool is_running = true;
const double dt = 0.016;

int main() {
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

    Logger::log("Enabling satellite systems...", "Main", "INFO");
    while(is_running) {
        board_computer.emulate(dt);
        controller.update(gps, imu, captors, power_system);
    }
    return EXIT_SUCCESS;
}