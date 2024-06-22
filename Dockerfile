FROM ubuntu:latest

RUN apt-get update && apt-get install -y curl
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=/usr/local/bin sh
RUN arduino-cli config init
RUN arduino-cli core update-index
RUN arduino-cli core install esp32:esp32

WORKDIR /workspace
CMD ["arduino-cli", "compile", "--fqbn", "esp32:esp32:esp32", "."]
