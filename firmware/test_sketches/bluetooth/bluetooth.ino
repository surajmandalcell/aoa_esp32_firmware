#include <ArduinoBLE.h>

// Constants for the BLE service and characteristic
const char SERVICE_NAME[] = "TextExchange";
const char CHARACTERISTIC_NAME[] = "TESTING";

class Bluetooth {
public:
  Bluetooth();
  void begin();
  void scanForDevices();
  BLEDevice available();
  void printPeripheralDetails(BLEDevice peripheral);
  bool connectToDevice(BLEDevice peripheral);
  void setDeviceName(const String& name);
  bool isConnected();

private:
  bool isInitialized;
  bool isConnectedInternal;
  BLEService printService{ SERVICE_NAME };
  BLECharacteristic printCharacteristic{
    CHARACTERISTIC_NAME, BLEWrite | BLERead | BLENotify, 512
  };
};

Bluetooth bleHelper;

void setup() {
  Serial.begin(115200);
  bleHelper.begin();
}

void loop() {
  if (!bleHelper.isConnected()) {
    BLEDevice peripheral = bleHelper.available();
    if (peripheral) {
      bleHelper.printPeripheralDetails(peripheral);
      if (bleHelper.connectToDevice(peripheral)) {
        // Additional interactions with the connected device
      }
    }
    delay(1000);  // Adjust delay as needed for scanning
  }
}

// Implementation of the Bluetooth class
Bluetooth::Bluetooth() {
  this->isInitialized(false);
  this->isConnectedInternal(false);
  this->printService(SERVICE_NAME);
  this->printCharacteristic(CHARACTERISTIC_NAME, BLEWrite | BLERead | BLENotify, 512) {}
}

void Bluetooth::begin() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (!BLE.begin()) {
    Serial.println("Starting BLE module failed!");
    while (1)
      ;
  }

  BLE.setLocalName("ArduinoBLE");
  BLE.setAdvertisedService(printService);
  printService.addCharacteristic(printCharacteristic);
  BLE.addService(printService);
  BLE.advertise();

  printCharacteristic.setEventHandler(
    BLEWritten, [](BLEDevice central, BLECharacteristic characteristic) {
      const uint8_t* data =
        characteristic.value();  // Get the pointer to the data
      size_t len =
        characteristic.valueLength();  // Get the length of the data

      Serial.print("Received via BLE: ");
      for (size_t i = 0; i < len; i++) {
        if (isalnum(data[i])) {  // Check if the character is alphanumeric
          Serial.print((char)data[i]);
        } else {
          Serial.print("[");
          Serial.print(data[i], HEX);  // Print non-alphanumeric as hex
          Serial.print("]");
        }
      }
      Serial.println();
    });

  Serial.println("BLE Ready and Advertising!");
  isInitialized = true;
}

void Bluetooth::scanForDevices() {
  if (isInitialized && !isConnectedInternal) {
    BLE.scan();
  }
}

BLEDevice Bluetooth::available() {
  if (!isConnectedInternal) {
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
  if (!isConnectedInternal && peripheral.connect()) {
    Serial.println("Connected successfully!");
    isConnectedInternal = true;
    return true;
  } else {
    Serial.println("Failed to connect or already connected.");
    return false;
  }
}

bool Bluetooth::isConnected() {
  return isConnectedInternal;
}

void Bluetooth::setDeviceName(const String& name) {
  BLE.setDeviceName(name.c_str());
  Serial.println("Device name set to: " + name);
}
