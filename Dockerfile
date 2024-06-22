FROM ubuntu:latest

RUN apt-get update && apt-get install -y curl python3 python3-pip
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=/usr/local/bin sh
RUN arduino-cli config init
RUN arduino-cli core update-index
RUN arduino-cli core install esp32:esp32

WORKDIR /esp32_firmware

COPY ./esp32_firmware.ino /esp32_firmware

CMD arduino-cli compile --fqbn esp32:esp32:nano_nora . --output-dir /esp32_firmware/build --build-path /esp32_firmware/build
