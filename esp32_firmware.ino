#include "lib/bluetooth_manager.h"
#include "lib/config.h"
#include "server.h"

void setup() {
  Serial.begin(115200);
  setupServer();
}

void loop() {
  loopServer();
}
