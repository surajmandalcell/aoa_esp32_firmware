# AOA ESP32 Firmware

This Firmware does the following:

- Connects to a WiFi to talk to server
- Connects to bluetooth switch
- Talks to openlog to get data off and to from the server over wifi
- Server can flash the device over the air

# Pre-requisites

- Install Arduino IDE
- Install ESP32 board in Arduino IDE
- Rename `firmware/esp32_firmware/env.example.h` to `firmware/esp32_firmware/env.h` and fill in the required values
