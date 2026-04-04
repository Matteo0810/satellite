#include <iostream>
#include "core/config.h"

#include "simulation/earth.h"

#include "modules/gps.h"

int main() {
    load_config("config/config.json");

    GPS gps;
    Planet earth;
    
    for (int i = 0; i < 10; i++) {
        std::cout << "Simulation " << (i + 1) << std::endl;
        gps.emulate(earth);
    }
    return EXIT_SUCCESS;
}