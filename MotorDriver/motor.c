#include <stdio.h>
#include <stdint.h>

#include "motor.h"
#include "gpio.h"

#define MOTOR_ENABLE_BIT 0
#define MOTOR_DIRECTION_BIT 1
#define MOTOR_BRAKE_BIT 2
#define MOTOR_SPEED_BITS_LENGTH 5
#define MOTOR_SPEED_BITS_START 3



void motor_init(Motor *motor, uint32_t *port, int pin){

    if(motor == NULL || port == NULL || (pin < 0 || pin > 15)) return;

    *port = 0;
    motor->control_reg = 0;
    motor->gpio_port = port;
    motor->enable_pin = pin; 
}

void motor_enable(Motor *motor){
    if(motor == NULL) return;

    motor->control_reg |= (1U << MOTOR_ENABLE_BIT);

    gpio_set_pin(motor->gpio_port, motor->enable_pin);
}

void motor_disable(Motor *motor){
    if(motor == NULL) return;

    motor->control_reg &= ~(1U << MOTOR_ENABLE_BIT);

    gpio_clear_pin(motor->gpio_port, motor->enable_pin);
}

void motor_set_direction(Motor *motor, int direction){
    if(motor == NULL) return;

    if(direction == 1){
        motor->control_reg |= (1U << MOTOR_DIRECTION_BIT); // Reverse
    }else if(direction == 0){
        motor->control_reg &= ~(1U << MOTOR_DIRECTION_BIT); // Forward
    }else{
        return; //nothing
    }
}

void motor_set_brake(Motor *motor, int brake){
    if(motor == NULL) return;

    if(brake == 1){
        motor->control_reg |= (1U << MOTOR_BRAKE_BIT); // brake
    }else if(brake == 0){
        motor->control_reg &= ~(1U << MOTOR_BRAKE_BIT); // free run
    }
}

void motor_set_speed(Motor *motor, uint8_t speed){
    if(motor == NULL) return;

    unsigned int mask = ((1U << MOTOR_SPEED_BITS_LENGTH) - 1) << MOTOR_SPEED_BITS_START; //create a mask of 5 bits at 1 and shift the bits to the starting position of the speed bits.

    motor->control_reg &= ~(mask); //clear the speed bits

    speed &= ((1U << MOTOR_SPEED_BITS_LENGTH ) - 1); //keep only the 5 low bit 

    motor->control_reg |= (speed << MOTOR_SPEED_BITS_START); // insert the values of speed into the control register
    
}

void motor_print_status(const Motor *motor){
    if(motor == NULL) return;
    printf("Motor Status\n");
    printf("------------\n");
    printf("Enable     : %s\n", (((motor->control_reg) >> MOTOR_ENABLE_BIT) & 1U) ? "ON":"OFF");
    printf("Direction  :%s\n",(((motor->control_reg) >> MOTOR_DIRECTION_BIT) & 1U)? " REVERSE ":" FORWARD ");
    printf("Brake      : %s\n", (((motor->control_reg) >> MOTOR_BRAKE_BIT) & 1U) ? "ON" : "OFF");
    printf("Speed      : %d\n", (motor->control_reg >> MOTOR_SPEED_BITS_START) & ((1U << MOTOR_SPEED_BITS_LENGTH) - 1));
    printf("Register   : %#x\n", motor->control_reg );    
}