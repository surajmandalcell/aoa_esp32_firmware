#include "BluetoothSerial.h"
#include "bluetooth_manager.h"

BluetoothSerial SerialBT;

void enableBluetooth() {
  if (!SerialBT.begin("ESP32_BT")) {
    Serial.println("Bluetooth init failed");
  } else {
    Serial.println("Bluetooth enabled");
  }
}

void disableBluetooth() {
  SerialBT.end();
  Serial.println("Bluetooth disabled");
}
