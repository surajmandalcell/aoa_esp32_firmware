build:
	docker build -t esp32_firmware .

run:
	docker stop esp32_firmware || true
	docker rm esp32_firmware || true
	docker run --name esp32_firmware -v $(shell pwd)/build:/esp32_firmware/build esp32_firmware

clean:
	docker rm esp32_firmware
	rm -rf build/*

all: build run

.PHONY: build run clean all
