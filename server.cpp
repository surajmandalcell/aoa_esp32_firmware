#include <WebServer.h>

#include "services/bluetooth_manager.h"
#include "services/config.h"
#include "services/wifi_manager.h"

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Device Info: ESP32");
}

void setupServer() {
  server.on("/", HTTP_GET, handleRoot);

  // Bluetooth Endpoints

  server.on("/v1/bluetooth/enable", HTTP_GET, []() {
    enableBluetooth();
    server.send(200, "text/plain", "Bluetooth enabled");
  });
  server.on("/v1/bluetooth/disable", HTTP_GET, []() {
    disableBluetooth();
    server.send(200, "text/plain", "Bluetooth disabled");
  });

  // WIFI Endpoints

  server.on("/v1/wifi/connect", HTTP_POST, []() {
    connectWiFi(ssid.c_str(), password.c_str());
    server.send(200, "text/plain", "Connecting to WiFi...");
  });

  server.on("/v1/wifi/disconnect", HTTP_GET, []() {
    disconnectWiFi();
    server.send(200, "text/plain", "Disconnected from WiFi");
  });

  server.on("/v1/wifi/scan", HTTP_GET, []() {
    scanNetworks();
    server.send(200, "text/plain", "Scanning WiFi networks...");
  });

  server.begin();
}

void loopServer() {
  server.handleClient();
}
