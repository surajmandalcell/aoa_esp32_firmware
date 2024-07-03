#include "env.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  connectWiFi(WIFI_SSID, WIFI_PASSWORD);
  // TODO: Handle the bluetooth switch
  // connectBluetoothSwitch()
}

void loop() {
}
