#include "env.h"
#include "wifi.h"
#include "serial_com.h"

AWifi awifi;
// ESP32 Nano RX and TX Pins, default baud rate is 115200
// Use 44 and 43 respectively if you want to use GPIO pin numbering instead
SerialCom serial_com(0, 1);

void setup() {
	Serial.begin(115200);
	serial_com.begin();

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
		} else if (input == "dir") {
			Serial.println(serial_com.menu_fs_dir());
		} else if (input == "clear") {
			for (int i = 0; i < 30; i++) Serial.println();
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
	Serial.println("'dir': List All Files in SD Card");
	Serial.println("'clear': Clear Terminal");
	Serial.println("Enter the number of the desired option:");
}

void monitorSerial() {
	Serial.println("Monitoring Serial1 (Type 'esc' to exit)...");
	while (true) {
		if (serial_com.available()) {
			String message = serial_com.receive();
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
	Serial.println("Type commands to send to Serial1 (Type 'esc' to return to menu):");
	while (true) {
		if (Serial.available()) {
			String command = Serial.readStringUntil('\n');
			command.trim();
			if (command == "esc") {
				clearSerialBuffer();
				return;	 // Exit the function and go back to the menu
			} else {
				serial_com.send(command);
			}
		}
	}
}

void clearSerialBuffer() {
	while (Serial.available() > 0) {
		Serial.read();	// Read and discard any residual data in the buffer
	}
}
