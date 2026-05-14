#include "../display/ssd1306.h"
#include "terminal.h"
#include "driver/uart.h"

#define URT_NUM UART_NUM_0
#define BUF_SIZE 1024
#define UART_BAUD_RATE  115200

void uart_init() {
    const uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(URT_NUM, &uart_config);
    uart_set_pin(URT_NUM, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(URT_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
    uint8_t data[BUF_SIZE];
    int i = 0;
    while (1) {
        int len = uart_read_bytes(URT_NUM, data, BUF_SIZE, pdMS_TO_TICKS(100));
        if (len > 0) {
            i++;
            data[len] = '\0';
            printf("Received: %s\n", data);
            oled_print(0, i, (char*)data);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
}
}