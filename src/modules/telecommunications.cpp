#include <iostream>
#include <algorithm>

#include "math/vec3.hpp"
#include "core/constants.hpp"
#include "core/logger.hpp"
#include "core/telemetry_buffer.hpp"

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
    const double distance_km = distance / 1000.0;
    
    const double latency = distance / CELERITY;

    const double scale = 20000.0;
    const double loss = 1.0 - exp(-distance_km / scale);

    Message message;
    message.arrivalTime = this->simTime + latency;
    message.loss = loss;
    message.payload = payload.dump();

    this->queue.push(message);
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
            telemetryBuffer.update(msg.payload);
        }
    }
}