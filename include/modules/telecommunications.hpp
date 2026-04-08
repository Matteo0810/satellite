#pragma once
#include <string>
#include <queue>
#include <nlohmann/json.hpp>

#include "simulation/celestal_body.hpp"

#include "core/mqtt_client.hpp"
#include "core/constants.hpp"

#include "modules/gps.hpp"

using json = nlohmann::json;

struct Message {
    float arrivalTime;
    float loss;
    std::string payload;
};
struct MessageCompare {
    bool operator()(const Message& a, const Message& b) {
        return a.arrivalTime > b.arrivalTime;
    }
};

class Telecommunications {
private:
    float latency;
    float loss;
    float simTime;
    std::priority_queue<Message, std::vector<Message>, MessageCompare> queue;
public:
    Telecommunications() : 
        latency(0),
        simTime(0),
        loss(0) {}
    float getLatency() const;
    float getLoss() const;
    void send(const json& payload, const GPS* gps, const Vec3 targetPosition);
    void emulate(const double dt);
};