#include "display/ssd1306.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void) {
    oled_init();
    oled_clear();
    oled_print(0, 0, "BYE MATE");

    while (1) vTaskDelay(pdMS_TO_TICKS(1000));
}