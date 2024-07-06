## Arduino Serial Communication Setup

### Configuration

Ensure your Arduino IDE is set to legacy pin code if you want to use legacy GPIO pin numbers for compatibility:

- Navigate to `Menu -> Tools -> Pin Numbering`.
- Select `By GPIO number (legacy)`.

### Code Setup

Define the RX and TX pin numbers used for serial communication:

```cpp
// const int _GPIO_RX_PIN 44;  // Incorrect definition (commented for reference)
// const int _GPIO_TX_PIN 43;  // Incorrect definition (commented for reference)
const int _RX_PIN = 0;    // Default Arduino pin number for RX
const int _TX_PIN = 1;    // Default Arduino pin number for TX
```

### Initialization

Initialize the serial ports in the `setup()` function:

```cpp
void setup() {
    long BAUD_RATE = 115200; // Set the baud rate
    Serial.begin(BAUD_RATE); // Start serial communication with the computer
    Serial1.begin(BAUD_RATE, SERIAL_8N1, _RX_PIN, _TX_PIN); // Start serial1 with device
}
```

### Main Loop

Check for incoming data and print it:

```cpp
void loop() {
    if (Serial1.available()) {
        Serial.println(Serial1.readStringUntil('
')); // Read and print data line-by-line
    }
}
```

**Note:** Ensure the baud rate (BAUD_RATE) matches the configuration of the device you are communicating with, such as OpenLog or another microcontroller.
