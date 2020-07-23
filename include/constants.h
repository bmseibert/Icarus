#pragma once
#include <pigpio.h>
#include <pigpiod_if2.h>

// These define the GPIO pins that control the Flight motorss
#define MOTORFR 17
#define MOTORFL 23
#define MOTORBR 18
#define MOTORBL 22
#define IMU_SDA 10
#define IMU_SCL 11
#define I2C_ADDRESS 0x68