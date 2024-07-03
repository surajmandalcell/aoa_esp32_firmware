#ifndef BLE_HELPER_H
#define BLE_HELPER_H

#include <ArduinoBLE.h>

#include "constants.h"	// Include the constants file

class Bluetooth {
public:
	Bluetooth();
	void begin();
	void scanForDevices();
	BLEDevice available();
	void printPeripheralDetails(BLEDevice peripheral);
	bool connectToDevice(BLEDevice peripheral);
	void setDeviceName(const String& name);
	void setupServiceAndAdvertise();

private:
	bool isInitialized;
	bool isConnected;
	BLEService printService{SERVICE_UUID};
	BLECharacteristic printCharacteristic{
			CHARACTERISTIC_UUID, BLEWrite | BLERead | BLENotify, 512};
};

#endif
