#pragma once
constexpr double G = 6.674e-11; // km-1/s-1
constexpr int CELERITY = 300000; // km/s

constexpr double DT = 0.001; // s

inline const char* get_broker_url()
{
    const char* env = std::getenv("BROKER_URL");
    return env ? env : "tcp://localhost:1883";
}

constexpr const char* BROKER_CLIENT_ID = "satellite";
constexpr const char* BROKER_TOPIC = "satellite/telemetry";