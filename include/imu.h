#pragma once
#include "motor_controller.h"
#include "constants.h"

class IMU
{
    private:
        int i2c = 0; // returned by i2c open
    public:
        int XGyroOffset = 0;
        int YGyroOffset = 0;
        int ZGyroOffset = 0;
        int ZAccelOffset = 0;
        IMU();
        void SetI2C(int newI2C);
        int GetI2C();
};