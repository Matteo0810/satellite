#include <nlohmann/json.hpp>
#include <fstream>
#include "core/config.hpp"

using json = nlohmann::json;
Config cfg;

void load_config(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open config file");
    }

    json j;
    file >> j;

    Config cfg;
    cfg.server = j.at("server").get<std::string>();
    cfg.client_id = j.at("client_id").get<std::string>();
    cfg.topic = j.at("topic").get<std::string>();
}