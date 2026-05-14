#include<stddef.h>
#include<stdckdint.h>
#include "../display/ssd1306.h"
#include "driver/uart.h"
#include "driver/gpio.h"

#define URT_NUM UART0
#define BUF_SIZE 1024
#define UART_BAUD_RATE  115200
void shell_init(){
    oled_init();
    oled_clear();
    
}