#include "display/ssd1306.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gui/Boot.h"
void app_main(void) {
    oled_init();
    oled_clear();
    start_booting_sequence();
    shell_init();
    while (1) vTaskDelay(pdMS_TO_TICKS(1000));
}