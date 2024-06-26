#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <string>

void connectWiFi(const char* ssid, const char* password);
void disconnectWiFi();
std::string scanWiFi();

#endif
