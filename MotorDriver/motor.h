#ifndef MOTOR_H
#define MOTOR_H


#include <stdint.h>

typedef struct{
    uint8_t control_reg; // control register
    uint32_t *gpio_port; // GPIO
    uint8_t enable_pin; // pin connected to the motor driver
}Motor;

void motor_init(Motor *motor, uint32_t *port, int pin);
void motor_enable(Motor *motor);
void motor_disable(Motor *motor);
void motor_set_direction(Motor *motor, int direction);
void motor_set_brake(Motor *motor, int brake);
void motor_set_speed(Motor *motor, uint8_t speed);
void motor_print_status(const Motor *motor);

#endif