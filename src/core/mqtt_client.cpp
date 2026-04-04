#include "core/mqtt_client.h"
#include "core/config.h"

void MqttClient::connect() {
    try {
        std::cout << "Connecting to broker: " << server_address << std::endl;

        mqtt::connect_options connOpts;
        connOpts.set_clean_session(true);
        connOpts.set_keep_alive_interval(20);

        auto tok = client->connect(connOpts);
        tok->wait();

        connected = true;

        std::cout << "MQTT connected successfully" << std::endl;

    } catch (const mqtt::exception& e) {
        connected = false;
        std::cerr << "MQTT connection error: " << e.what() << std::endl;
        throw;
    }
}
void MqttClient::publish(const std::string& topic,
                          const std::string& payload,
                          int qos) {
    try {
        if (!connected) {
            std::cerr << "MQTT not connected, cannot publish" << std::endl;
            return;
        }

        auto msg = mqtt::make_message(topic, payload);
        msg->set_qos(qos);

        auto tok = client->publish(msg);
        tok->wait();

        std::cout << "Published to " << topic
                  << " : " << payload << std::endl;

    } catch (const mqtt::exception& e) {
        std::cerr << "Publish error: " << e.what() << std::endl;
    }
}