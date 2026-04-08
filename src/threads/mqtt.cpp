#include "core/mqtt_client.hpp"
#include "core/telemetry_buffer.hpp"

void mqttLoop() {
    auto& mqtt = getMqttClient();

    while (true) {
        std::string data = telemetryBuffer.get();
        if (!data.empty()) {
            mqtt.publish(data);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}