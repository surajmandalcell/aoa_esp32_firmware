#include "env.h"
#include "serial_com.h"
#include "wifi.h"

AWifi awifi;
SerialCom _SerialCom(44, 43);	 // ESP32 Nano RX and TX Pins

void setup() {
	Serial.begin(115200);
	_SerialCom.begin();

	// Handling Wifi Connection
	awifi.connectWifi(WIFI_SSID, WIFI_PASSWORD);

	displayMenu();
}

void loop() {
	if (Serial.available()) {
		String input = Serial.readStringUntil('\n');
		input.trim();	 // Clean up any whitespace or newline characters

		if (input == "1") {
			monitorSerial();
		} else if (input == "2") {
			sendSerialCommands();
		} else if (input == "esc") {
			// Esc logic, if any additional is needed
		} else if (input == "") {
			// Handling empty input if necessary
		} else {
			Serial.println("Invalid option. Try again.");
		}
		displayMenu();
		clearSerialBuffer();
	}
}

void displayMenu() {
	Serial.println("\n### MENU ###");
	Serial.println("1: Monitor Serial1 Messages");
	Serial.println("2: Send Commands to Serial1");
	Serial.println("Enter the number of the desired option:");
}

void monitorSerial() {
	Serial.println("Monitoring Serial1 (Type 'esc' to exit)...");
	while (true) {
		if (_SerialCom.available()) {
			String message = _SerialCom.receive();
			Serial.print("Received: ");
			Serial.println(message);
		}
		if (Serial.available()) {
			String command = Serial.readStringUntil('\n');
			command.trim();
			if (command == "esc") {
				clearSerialBuffer();
				return;	 // Exit the function and go back to the menu
			}
		}
	}
}

void sendSerialCommands() {
	Serial.println(
			"Type commands to send to Serial1 (Type 'esc' to return to menu):");
	while (true) {
		if (Serial.available()) {
			String command = Serial.readStringUntil('\n');
			command.trim();
			if (command == "esc") {
				clearSerialBuffer();
				return;	 // Exit the function and go back to the menu
			}
			_SerialCom.send(command);
		}
	}
}

void clearSerialBuffer() {
	while (Serial.available() > 0) {
		Serial.read();	// Read and discard any residual data in the buffer
	}
}
