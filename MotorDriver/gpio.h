#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>



void gpio_set_pin(uint32_t *reg, int pin);
void gpio_clear_pin(uint32_t *reg, int pin);
void gpio_toggle_pin(uint32_t *reg, int pin);
int gpio_read_pin(uint32_t reg, int pin);


#endif