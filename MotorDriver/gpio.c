#include <stdlib.h>
#include <stdint.h>

#include "gpio.h"

void gpio_set_pin(uint32_t *reg, int pin){
    if((pin < 0 || pin > 15) || reg == NULL) return;

    *reg |= (1U << pin);
}

void gpio_clear_pin(uint32_t *reg, int pin){
    if((pin < 0 || pin > 15) || reg == NULL) return;

    *reg &= ~(1U << pin);
}

void gpio_toggle_pin(uint32_t *reg, int pin){
    if((pin < 0 || pin > 15) || reg == NULL) return;

    *reg ^= (1U << pin);
}

int gpio_read_pin(uint32_t reg, int pin){
    if((pin < 0 || pin > 15)) return -1;

    return (reg >> pin) & 1U;
}