#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <string>

#include "services/bluetooth_manager.h"
#include "services/config.h"
#include "services/wifi_manager.h"

AsyncWebServer server(80);

void handleRoot(AsyncWebServerRequest *request)
{
  request->send(200, "text/plain", "Device Info: ESP32");
}

void setupServer()
{
  server.on("/", HTTP_GET, handleRoot);

  // Bluetooth Endpoints

  server.on(
      "/v1/bluetooth/enable", HTTP_GET, [](AsyncWebServerRequest *request)
      {
        enableBluetooth();
        request->send(200, "text/plain", "Bluetooth enabled"); });
  server.on(
      "/v1/bluetooth/disable", HTTP_GET, [](AsyncWebServerRequest *request)
      {
        disableBluetooth();
        request->send(200, "text/plain", "Bluetooth disabled"); });

  // WIFI Endpoints

  server.on(
      "/v1/wifi/connect", HTTP_POST, [](AsyncWebServerRequest *request) {},
      nullptr,
      [](AsyncWebServerRequest *request, uint8_t *data, size_t len,
         size_t index, size_t total)
      {
        if (!index)
        {
          Serial.println("Receive POST data start");
        }
        Serial.printf("Received POST data chunk with length: %u\n", len);
        if (index + len == total)
        {
          Serial.println("Receive POST data end");
        }

        request->send(200, "text/plain", "Data received");
      });

  server.on(
      "/v1/wifi/disconnect", HTTP_GET, [](AsyncWebServerRequest *request)
      {
        disconnectWiFi();
        request->send(200, "text/plain", "Disconnected from WiFi"); });

  server.on("/v1/wifi/scan", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    std::string networks = scanWiFi();
    request->send(200, "text/plain", networks.c_str()); });

  server.begin();
}

void loopServer()
{
}