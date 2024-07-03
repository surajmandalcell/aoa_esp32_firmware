#ifndef BLE_HELPER_H
#define BLE_HELPER_H

#include <ArduinoBLE.h>

class Bluetooth {
public:
  Bluetooth();
  void begin();
  void scanForDevices();
  BluetoothDevice available();
  void printPeripheralDetails(BluetoothDevice peripheral);

private:
  bool isInitialized;
};

#endif
