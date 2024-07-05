#define RX 44
#define TX 43

void setup() {
	long BAUD_RATE = 115200;
	Serial.begin(BAUD_RATE);
	Serial1.begin(BAUD_RATE, SERIAL_8N1, RX, TX);
}

void loop() {
	if (Serial1.available()) {
		Serial.println(Serial1.readStringUntil('\n'));
	}
}
