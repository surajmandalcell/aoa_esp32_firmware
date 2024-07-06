void setup() {
	// NOTE: Make sure Arduino IDE is set to legacy pin code if you want to use legacy GPIO pin
	// numbers for compatability Menu->Tools->Pin Numbering->By GPIO number (legacy)
	// const int _GPIO_RX_PIN 44;
	// const int _GPIO_TX_PIN 43;
	const int _RX_PIN = 0;	// Default Arduino pin number for rx
	const int _TX_PIN = 1;	// Default Arduino pin number for tx
	// NOTE: Make sure to set the same in openlog or other device you're communicating with
	long BAUD_RATE = 115200;
	Serial.begin(BAUD_RATE);
	Serial1.begin(BAUD_RATE, SERIAL_8N1, _RX_PIN, _TX_PIN);
}

void loop() {
	if (Serial1.available()) {
		Serial.println(Serial1.readStringUntil('\n'));
	}
}
