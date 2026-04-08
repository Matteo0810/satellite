#include <iostream>
#include <thread>

#include "core/mqtt_client.hpp"

#include "threads/mqtt.hpp"
#include "threads/simulation.hpp"

int main() {
    auto& mqtt = getMqttClient();
    mqtt.connect();

    std::thread sim(simulationLoop);
    std::thread net(mqttLoop);
    
    net.join();
    sim.join();

    return EXIT_SUCCESS;
}