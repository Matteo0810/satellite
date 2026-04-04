default_target: build

build:
	mkdir -p build && \
	cd build && \
	cmake .. && \
	make
.PHONY: build

run:
	./build/satellite
.PHONY: run