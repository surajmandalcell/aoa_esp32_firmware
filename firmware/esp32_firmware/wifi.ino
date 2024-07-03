#include <WiFi.h>

void connectWiFi(const char* ssid, const char* password) {
  Serial.begin(115200);
  WiFi.disconnect();  // Ensure any previous session is disconnected
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED &&
         attempts < 30) {  // Attempt for 15 seconds
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected successfully");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to WiFi");
  }
}
