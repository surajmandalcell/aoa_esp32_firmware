#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "example";

extern "C" void app_main()
{
    while (1)
    {
        ESP_LOGI(TAG, "Hello, World!");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}
