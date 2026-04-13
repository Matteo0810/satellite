FROM gcc:15.2.0 AS builder

WORKDIR /app
COPY . .

RUN apt-get update && apt-get install -y \
    cmake libpaho-mqttpp-dev libpaho-mqtt-dev nlohmann-json3-dev

RUN mkdir build && cd build && cmake .. && make


FROM debian:bookworm-slim

WORKDIR /app

RUN apt-get update && apt-get install -y \
    libpaho-mqttpp3-1 \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/build/satellite /app/satellite

ENV LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu

CMD ["./satellite"]