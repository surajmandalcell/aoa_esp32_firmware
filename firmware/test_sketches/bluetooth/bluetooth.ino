#include "ble.h"

BLEHelper bleHelper;

void setup() {
  bleHelper.begin();
}

void loop() {
  bleHelper.scanForDevices();
  BLEDevice peripheral = bleHelper.available();
  bleHelper.printPeripheralDetails(peripheral);
}
