cmake_minimum_required(VERSION 3.10)
project(satellite)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(satellite ${SOURCES})

target_include_directories(satellite PRIVATE include)

target_link_libraries(satellite
    paho-mqttpp3
    paho-mqtt3a
)