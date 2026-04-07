#include <mqtt/async_client.h>
#include <string>

class MqttClient {
public:
    MqttClient(
        const std::string& server, 
        const std::string& client_id,
        const std::string& topic
    )
        : server_address(server),
          client_id(client_id),
          topic(topic),
          client(std::make_unique<mqtt::async_client>(server, client_id)),
          connected(false) {}

    void connect();
    void publish(const std::string& payload, int qos = 1);

private:
    std::string server_address;
    std::string client_id;
    std::string topic;

    std::unique_ptr<mqtt::async_client> client;
    bool connected;
};