#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>
#include <stddef.h>

void oled_init(void);
void oled_clear(void);
void oled_print(uint8_t page, uint8_t col, const char *str);

#endif