#include "ble.h"

Bluetooth::Bluetooth() : isInitialized(false) {
}

void Bluetooth::begin() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  isInitialized = true;
  Serial.println("Bluetooth® Low Energy Central scan");
}

void Bluetooth::scanForDevices() {
  if (isInitialized) {
    BLE.scan();
  }
}

BluetoothDevice Bluetooth::available() {
  return BLE.available();
}

void Bluetooth::printPeripheralDetails(BluetoothDevice peripheral) {
  if (peripheral) {
    Serial.println("Discovered a peripheral");
    Serial.println("-----------------------");
    Serial.print("Name: ");
    Serial.println(peripheral.localName());
    Serial.print("Address: ");
    Serial.println(peripheral.address());

    if (peripheral.hasLocalName()) {
      Serial.print("Local Name: ");
      Serial.println(peripheral.localName());
    }

    if (peripheral.hasAdvertisedServiceUuid()) {
      Serial.print("Service UUIDs: ");
      for (int i = 0; i < peripheral.advertisedServiceUuidCount(); i++) {
        Serial.print(peripheral.advertisedServiceUuid(i));
        Serial.print(" ");
      }
      Serial.println();
    }

    Serial.print("RSSI: ");
    Serial.println(peripheral.rssi());
    Serial.println();
  }
}
