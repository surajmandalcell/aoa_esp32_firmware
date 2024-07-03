#include "ble.h"

Bluetooth bleHelper;

void setup() {
  Serial.begin(115200);
	bleHelper.begin();
}

void loop() {
	BLEDevice peripheral = bleHelper.available();
	if (peripheral) {
		Serial.print(peripheral.deviceName());
		Serial.print(peripheral.address());
		bleHelper.printPeripheralDetails(peripheral);
		bleHelper.connectToDevice(peripheral);
	}
	delay(1000);
}
