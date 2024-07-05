#include "serial_com.h"

SerialCom::SerialCom(int rxPin, int txPin, long baudRate)
		: _rxPin(rxPin), _txPin(txPin), _baudRate(baudRate) {
}

void SerialCom::begin() {
	Serial1.begin(_baudRate, SERIAL_8N1, _rxPin, _txPin);
}

void SerialCom::send(String data) {
	Serial1.println(data);
}

String SerialCom::receive() {
	if (Serial1.available()) {
		return Serial1.readStringUntil('\n');
	}
	return String("");
}

int SerialCom::available(){
  return Serial1.available();
}