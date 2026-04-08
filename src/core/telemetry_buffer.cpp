#include "core/telemetry_buffer.hpp"

void TelemetryBuffer::update(const std::string& data) {
    std::lock_guard<std::mutex> lock(mtx);
    latest = data;
}
std::string TelemetryBuffer::get() {
    std::lock_guard<std::mutex> lock(mtx);
    return latest;
}

TelemetryBuffer telemetryBuffer;