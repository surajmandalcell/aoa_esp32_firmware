#include "ble.h"

Bluetooth::Bluetooth()
		: isInitialized(false),
			isConnected(false),
			printService(SERVICE_UUID),
			printCharacteristic(
					CHARACTERISTIC_UUID, BLEWrite | BLERead | BLENotify, 512) {
}

void Bluetooth::begin() {
	Serial.begin(9600);
	while (!Serial);

	if (!BLE.begin()) {
		Serial.println("Starting BLE module failed!");
		while (1);
	}

	BLE.setLocalName("ArduinoBLE");
	BLE.setAdvertisedService(printService);
	printService.addCharacteristic(printCharacteristic);
	BLE.addService(printService);
	BLE.advertise();

	printCharacteristic.setEventHandler(
			BLEWritten, [](BLEDevice central, BLECharacteristic characteristic) {
				const uint8_t* data =
						characteristic.value();	 // Get the pointer to the data
				size_t len =
						characteristic.valueLength();	 // Get the length of the data

				Serial.print("Received via BLE: ");
				for (size_t i = 0; i < len; i++) {
					if (isalnum(data[i])) {	 // Check if the character is alphanumeric
						Serial.print((char)data[i]);
					} else {
						Serial.print("[");
						Serial.print(data[i], HEX);	 // Print non-alphanumeric as hex
						Serial.print("]");
					}
				}
				Serial.println();
			});

	Serial.println("BLE Ready and Advertising!");
	isInitialized = true;
}

void Bluetooth::scanForDevices() {
	if (isInitialized && !isConnected) {
		BLE.scan();
	}
}

BLEDevice Bluetooth::available() {
	if (!isConnected) {
		return BLE.available();
	}
	return BLEDevice();
}

void Bluetooth::printPeripheralDetails(BLEDevice peripheral) {
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

bool Bluetooth::connectToDevice(BLEDevice peripheral) {
	if (!isConnected && peripheral.connect()) {
		Serial.println("Connected successfully!");
		isConnected = true;
		return true;
	} else {
		Serial.println("Failed to connect or already connected.");
		return false;
	}
}

void Bluetooth::setDeviceName(const String& name) {
	BLE.setDeviceName(name.c_str());
	Serial.println("Device name set to: " + name);
}
