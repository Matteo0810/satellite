cmake_minimum_required(VERSION 3.10)
project(satellite)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(satellite ${SOURCES})
target_include_directories(satellite PRIVATE include)

target_include_directories(satellite PRIVATE
    /opt/homebrew/include
    /usr/local/include
)
target_link_directories(satellite PRIVATE
    /opt/homebrew/lib
    /usr/local/lib
)

find_package(PahoMqttCpp REQUIRED)
find_package(nlohmann_json REQUIRED)

target_link_libraries(satellite
    PahoMqttCpp::paho-mqttpp3
    nlohmann_json::nlohmann_json
)

target_link_libraries(satellite
    paho-mqttpp3
    paho-mqtt3a
)