#include <Arduino.h>

#include "server.h"
#include "services/bluetooth_manager.h"
#include "services/config.h"

void setup() {
  Serial.begin(115200);
  setupServer();
}

void loop() {
  loopServer();
}
