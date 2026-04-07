#pragma once
#include <iostream>
#include <string>

class Logger {
public:
    static void log(const std::string& message);
    static void log(const std::string& message, const std::string& moduleName);
    static void log(const std::string& message, const std::string& moduleName, const std::string& severity);
};