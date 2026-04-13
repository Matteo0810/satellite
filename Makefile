default_target: build

build:
	mkdir -p build && \
	cd build && \
	cmake .. && \
	make
.PHONY: build

build-image:
	docker build -t satellite:latest .
.PHONY: build-image

run:
	./build/satellite
.PHONY: run