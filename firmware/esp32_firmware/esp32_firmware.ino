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
		input.trim();	 // Correctly use trim() on the existing String object
		if (input == "1") {
			monitorSerial();
			displayMenu();
		} else if (input == "2") {
			sendSerialCommands();
			displayMenu();
		} else if (input == "esc") {
			displayMenu();
		} else if (input == "") {
			displayMenu();
		} else {
			Serial.println("Invalid option. Try again.");
			displayMenu();
		}
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
	while (Serial.available() ==
				 0) {	 // Continue monitoring until there's input on Serial
		if (_SerialCom.available()) {
			String message = _SerialCom.receive();
			Serial.print("Received: ");
			Serial.println(message);
		}
	}
	// Exit on any input
}

void sendSerialCommands() {
	Serial.println(
			"Type commands to send to Serial1 (Type 'esc' to return to menu):");
	while (true) {
		if (Serial.available()) {
			String command = Serial.readStringUntil('\n');
			command.trim();	 // Correctly use trim()
			if (command == "esc") {
				return;	 // Return to menu on 'esc'
			}
			_SerialCom.send(command);
		}
	}
}