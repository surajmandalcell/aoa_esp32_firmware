# AOA ESP32 Firmware

This repository contains the firmware for ESP32 Nano Board for AOA project.

## Getting Started

### Prerequisites

#### Hardware

- [ESP32 Nano Board](https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us)
- [USB-C Cable](https://www.amazon.ca/s?k=type+c&crid=30F1MMUIOLNLO&sprefix=type+c%2Caps%2C103&ref=nb_sb_noss_1)

#### Software

- [VS Code](https://code.visualstudio.com)
- [Docker](https://docs.docker.com/get-docker)
- Build tools
  - Linux: `sudo apt-get install build-essential`
  - MacOS: `xcode-select --install`
  - Windows: [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install)

or

- [Arduino IDE](https://www.arduino.cc/en/software)

### Installation

1. Clone the repository
   ```sh
   git clone https://github.com/surajmandalcell/esp32_firmware.git
   ```
2. Change directory to the repository
   ```sh
   cd esp32_firmware
   ```
3. Use make to build the project
   ```sh
   make all
   ```
4. Upload the firmware to the board
   ```sh
   make upload
   ```
