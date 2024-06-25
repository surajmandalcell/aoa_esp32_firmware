#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

void connectWiFi(const char* ssid, const char* password);
void disconnectWiFi();
void scanNetworks();

#endif
