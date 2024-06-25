#include <ESPAsyncWebServer.h>

#include "lib/bluetooth_manager.h"
#include "lib/config.h"
#include "lib/wifi_manager.h"

AsyncWebServer server(80);

void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/plain", "Device Info: ESP32");
}

void setupServer() {
  server.on("/", HTTP_GET, handleRoot);

  // Bluetooth Endpoints

  server.on(
      "/v1/bluetooth/enable", HTTP_GET, [](AsyncWebServerRequest *request) {
        enableBluetooth();
        request->send(200, "text/plain", "Bluetooth enabled");
      });
  server.on(
      "/v1/bluetooth/disable", HTTP_GET, [](AsyncWebServerRequest *request) {
        disableBluetooth();
        request->send(200, "text/plain", "Bluetooth disabled");
      });

  // WIFI Endpoints

  server.on(
      "/v1/wifi/connect", HTTP_POST, [](AsyncWebServerRequest *request) {},
      [](AsyncWebServerRequest *request, uint8_t *data, size_t len,
          size_t index, size_t total) {
        // Variables to store SSID and password
        String ssid = "";
        String password = "";

        // Parse POST data
        if (request->hasParam("ssid", true) &&
            request->hasParam("password", true)) {
          ssid = request->getParam("ssid", true)->value();
          password = request->getParam("password", true)->value();
          connectWiFi(ssid.c_str(), password.c_str());
          request->send(200, "text/plain", "Connecting to WiFi...");
        } else {
          request->send(400, "text/plain", "Missing SSID or password");
        }
      });

  server.on(
      "/v1/wifi/disconnect", HTTP_GET, [](AsyncWebServerRequest *request) {
        disconnectWiFi();
        request->send(200, "text/plain", "Disconnected from WiFi");
      });

  server.on("/v1/wifi/scan", HTTP_GET, [](AsyncWebServerRequest *request) {
    String networks =
        scanNetworks();  // assuming this function returns a string
    request->send(200, "text/plain", networks);
  });

  server.begin();
}

void loopServer() {
}