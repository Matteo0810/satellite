#include <iostream>

struct Config {
    std::string server;
    std::string client_id;
    std::string topic;
};

extern Config cfg;
void load_config(const std::string& path);