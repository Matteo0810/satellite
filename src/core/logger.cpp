#include "core/logger.hpp"

void Logger::log(const std::string& message) {
    std::cout << message << std::endl;
}
void Logger::log(const std::string& message, const std::string& moduleName) {
    std::cout << "[" << moduleName << "] " << message << std::endl;
}
void Logger::log(const std::string& message, const std::string& moduleName, const std::string& severity) {
    std::cout << "[" << severity << "] [" << moduleName << "] " << message << std::endl;
}