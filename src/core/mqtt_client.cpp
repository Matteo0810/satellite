#include "core/mqtt_client.hpp"

std::mutex mqttMutex;

void MqttClient::connect() {
    std::lock_guard<std::mutex> lock(mqttMutex);

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
void MqttClient::publish(const std::string& payload, int qos) {
    try {
        if (!client || !client->is_connected()) {
            std::cerr << "[MQTT] not connected\n";
            return;
        }

        auto msg = mqtt::make_message(topic, payload);
        msg->set_qos(qos);

        client->publish(msg)->wait();

    } catch (const mqtt::exception& e) {
        std::cerr << "[MQTT ERROR publish] " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "[MQTT ERROR unknown exception]\n";
    }
}

void MqttClient::ensureConnected() {
    std::lock_guard<std::mutex> lock(mqttMutex);

    if (client->is_connected()) return;

    mqtt::connect_options opts;
    opts.set_clean_session(true);
    opts.set_keep_alive_interval(20);

    client->connect(opts)->wait();

}

MqttClient& getMqttClient() {
    static MqttClient instance(
        get_broker_url(),
        BROKER_CLIENT_ID,
        BROKER_TOPIC
    );
    return instance;
}
