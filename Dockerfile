FROM ubuntu:latest

RUN apt-get update && apt-get install -y curl python3 python3-pip python3-serial
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=/usr/local/bin sh
RUN arduino-cli config init
RUN arduino-cli core update-index
RUN arduino-cli core install esp32:esp32

WORKDIR /esp32_firmware

COPY ./esp32_firmware.ino /esp32_firmware

# Create build directories
RUN mkdir -p /esp32_firmware/build /esp32_firmware/internal_build

# Command to compile the Arduino sketch and copy output to mounted directory
CMD arduino-cli compile --fqbn esp32:esp32:nano_nora /esp32_firmware/esp32_firmware.ino --output-dir /esp32_firmware/internal_build --build-path /esp32_firmware/internal_build && cp -r /esp32_firmware/internal_build/* /esp32_firmware/build/
