#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "motor.h"
#include "gpio.h"

int main(){

    uint32_t GPIOA = 0;
    Motor motor1;

    motor_init(&motor1, &GPIOA, 5);

    motor_enable(&motor1);
    motor_set_direction(&motor1,1);
    motor_set_brake(&motor1,1);
    motor_set_speed(&motor1,25);
   
    //motor_disable(&motor1);

    motor_print_status(&motor1);
    printf("\n");
    printf("%u", GPIOA);
    


    return 0;
}