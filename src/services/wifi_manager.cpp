#include "wifi_manager.h"

#include <Arduino.h>
#include <WiFi.h>

#include <string>

void connectWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void disconnectWiFi() {
  WiFi.disconnect();
  Serial.println("Disconnected from WiFi");
}

std::string scanWiFi() {
  std::string result = "Scanning for WiFi networks...\n";
  int numNetworks = WiFi.scanNetworks();
  result += (numNetworks == 0) ? "No networks found." : "";
  for (int i = 0; i < numNetworks; ++i) {
    result += std::string(WiFi.SSID(i).c_str()) + "\n";
  }
  return result;
}