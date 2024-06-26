#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "server.h"
#include "services/bluetooth_manager.h"
#include "services/config.h"

void setup()
{
    Serial.begin(115200);
    setupServer();
}

void loop()
{
    loopServer();
}