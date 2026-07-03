

# Motor Driver Firmware Simulation in C


A modular Embedded C project simulating a basic DC motor driver firmware.

This project was built as part of my my journey into **Embedded Systems** and **Robotics Engineering**.
It simulates how a microcontroller (such as STM32) could control a motor driver using GPIO and internal control registers.

---

## Project Overview

The firmware models a motor driver capable of:

- Enabling / disabling the motor
- Controlling motor direction
- Applying brake mode
- Setting motor speed using bit fiels
- Monitoring motor status through a control register

This project focuses on low-level programming concepts commonly used in embedded systems.

---

## Features

- GPIO simulation
- Register-level control
- Bitwise manipulation
- Multi-file C architecture
- Motor abstraction using structs
- Status monitoring and debugging

---

## Project Architecture

```text
main.c
gpio.h
gpio.c
motor.h
motor.c
```

## Control Register Layout

the motor driver uses an 8-bit control register.

| Bit(s) | Function |
|--------|----------|
|   0    | Enable   |
|   1    | Direction   |
|   2    | Brake   |
|   3-7    | Speed   |

### Direction Encoding

- 0 -> FORWARD
- 1 -> REVERSE

### Brake Encoding

- 0 -> OFF
- 1 -> ON


## Motor Structure

```c
typedef struct{
    uint8_t control_reg;
    uint32_t *gpio_port;
    uint8_t enable_pin;
} Motor;
```

- `control_reg` stores motor configuration
- `gpio_port` simulates the MCU GPIO register
- `enable_pin` represents the GPIO pin connected to the motor driver


# Build and Run

````markdown
## Build and Run
````

Compile using GCC:

```bash
gcc main.c gpio.c motor.c -o motor
,/motor

---
```


# Example output

````markdownn
## Example Output
````

```text
Motor Status
------------
Enable     : ON
Direction  : REVERSE
Brake      : ON
Speed      : 25
Register   : 0xCF
```


## Concepts Practiced

This project helped me practice:

- Embeddec C programming
- Bitwise operations
- Register manipulation
- Hardware abstraction
- Modular software design
- Firmware testing


## Key Learning

This project taught me that firmware design directly affects robot behavior.

One important design question was:

Should desabling a motor preserve its previous configuration, or reset everything for safety?

For mobile robots, a full reset can improve safety during obstacle detection and emergency stop scenarios.

## Futur Improvements

Planned extensions:

- PWM speed control
- Dual motor support
- Fault detection
- STM32 implementation
- Integration with robotic motion control

## Author

Christ Agnissan

Robotics Engineering Student
Interested in:
- Embedded Systems
- Motor Control
- Robotics Motion Planning





