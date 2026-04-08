#include <iostream>

class TelemetryBuffer {
public:
    void update(const std::string& data);
    std::string get();
private:
    std::string latest;
    std::mutex mtx;
};

extern TelemetryBuffer telemetryBuffer;