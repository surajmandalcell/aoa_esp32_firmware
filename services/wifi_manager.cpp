#include "WiFi.h"
#include "wifi_manager.h"

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

void scanNetworks() {
  Serial.println("Scanning for WiFi networks...");
  int numNetworks = WiFi.scanNetworks();
  if (numNetworks == 0) {
    Serial.println("No networks found.");
  } else {
    for (int i = 0; i < numNetworks; ++i) {
      Serial.println(WiFi.SSID(i));
    }
  }
}
