#include "modules/board_computer.hpp"
#include "simulation/celestal_body.hpp"

void BoardComputer::emulate(const double dt) {
    this->gps.emulate(earth, dt);
    this->powerSystem.emulate(dt);
    this->telecommunications.emulate(dt);
    this->captors.emulate(gps.getPosition(), sun.position, earth.position);
    this->imu.emulate(gps, dt);
}