#ifndef BOOT_H
#define BOOT_H

#include<stdint.h>
#include<stddef.h>
void keyframe(char value, uint8_t page, uint8_t column);
void start_booting_sequence(void);

#endif