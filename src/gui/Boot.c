
#include "Boot.h"
#include "../display/ssd1306.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h" 
#define COL_NUM 20

void keyframe(char value, uint8_t page, uint8_t column) {
    char str[2] = {value, '\0'};
    oled_print(page, column, str);
}

void print_name(){
    char name[] = "EMBOS";
    for(int i=0;name[i]!='\0';i++){
        keyframe(name[i], 7, COL_NUM+i);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void start_booting_sequence(void) {
    for(int i =0;i<80;i++){
        keyframe('@', 3, COL_NUM+i);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    print_name();
     vTaskDelay(pdMS_TO_TICKS(100));
    oled_clear();
}