#include "imu.h"

IMU::IMU(int& pi, const int& imu_sda, const int& imu_scl)
{
    // Initialize 
}

void IMU::SetI2C(int& newI2C){this->i2c = newI2C;}
int IMU::GetI2C(){return this->i2c;}