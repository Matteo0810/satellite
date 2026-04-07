#include <iostream>
#include <algorithm>

#include "math/vec3.hpp"
#include "core/constants.hpp"
#include "core/logger.hpp"
#include "modules/telecommunications.hpp"

float Telecommunications::getLatency() const {
    return this->latency;
}
float Telecommunications::getLoss() const {
    return this->loss;
}
void Telecommunications::send(const json& payload, const GPS* gps, const Vec3 targetPosition) {
    const Vec3 ES = targetPosition - gps->getPosition();
    const double distance = ES.length();

    const double latency = distance / celerity;

    const double r = (double)rand() / RAND_MAX;
    const double loss = std::clamp(distance * r, 0.0, 1.0);

    Message message;
    message.arrivalTime = this->simTime + latency;
    message.loss = loss;
    message.payload = payload.dump();

    this->queue.push(message);
    Logger::log("Message content: " + payload.dump(), "Telecommunications", "INFO");
}
void Telecommunications::emulate(const double dt) {
    this->simTime += dt;

    while (!this->queue.empty()) {
        const Message msg = this->queue.top();

        if (msg.arrivalTime > this->simTime) {
            break;
        }

        this->queue.pop();

        double r = (double)rand() / RAND_MAX;

        if (r >= msg.loss) {
            this->client->publish(msg.payload);
        }
    }
}