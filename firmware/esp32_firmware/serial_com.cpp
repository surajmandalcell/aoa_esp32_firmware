#include "serial_com.h"

SerialCom::SerialCom(int rxPin, int txPin, long baudRate)
		: _rxPin(rxPin), _txPin(txPin), _baudRate(baudRate) {
}

void SerialCom::begin() {
	Serial1.begin(_baudRate, SERIAL_8N1, _rxPin, _txPin);
}

int SerialCom::available() {
	return Serial1.available();
}

void SerialCom::flush() {
	while (Serial1.available()) {
		Serial1.read();	 // Clear the buffer
	}
}

void SerialCom::send(String data) {
	delay(250);
	Serial1.println(data);
}

String SerialCom::receive() {
	if (Serial1.available()) {
		return Serial1.readStringUntil('\n');
	}
	return String("");
}

String SerialCom::read() {
	this->flush();
	String result;
	while (Serial1.available()) {
		result += Serial1.readString();
		delay(10);	// Small delay to allow buffer to fill
	}
	return result;
}

String SerialCom::menu_fs_dir() {
	this->send("x");
	delay(2000);
	this->send("s");
	delay(2000);
	this->send("dir");
	delay(2000);
	String dir = this->read();
	delay(2000);
	return dir;
}