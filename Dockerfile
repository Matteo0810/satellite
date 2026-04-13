FROM gcc:15.2.0 AS builder

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    cmake \
    libpaho-mqttpp-dev \
    nlohmann-json3-dev

RUN mkdir build && cd build \
    && cmake .. \
    && make

FROM debian:bookworm-slim

WORKDIR /app

COPY --from=builder /app/build/satellite /app/satellite

CMD ["./satellite"]