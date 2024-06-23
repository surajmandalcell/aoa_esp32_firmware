#include "services/config.h"
#include "server.h"
#include "services/bluetooth_manager.h"

void setup() {
  Serial.begin(115200);
  setupServer();
}

void loop() {
  loopServer();
}
