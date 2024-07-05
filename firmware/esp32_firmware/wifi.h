#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>

class AWifi {
public:
	AWifi();
	void connectWifi(const char* ssid, const char* password);

private:
	String device_ip;
};

#endif