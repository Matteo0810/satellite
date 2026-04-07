# Satellite
This project aims to simulate launched satellite in space, that rotate arround the earth. \
It aims to be connected in real-time with a "earth station" (mqtt server) and be displayed on a web dashboard.

## Available modules
### Power system
- batteries
- solar pannel production
### Telecommunications
- latency
- signal loss
- payload sent to earth
# GPS
- x, y, z position
- orbitale speed
### IMU
- rotation
- pitch, yaw, roll
### Environmental captors
- temperature
- solar flux
- radiation level
### Board computer
- captors' reading
- decisions (normal mode, critical state, economic mode)
- data sending

## Technology used
- **C++**: common language used for embedding systems (with C as well).
- **MQTT Client**: mqtt aims to send in real-time all data sent from the satellite.