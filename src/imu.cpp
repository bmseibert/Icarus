#include "imu.h"

IMU::IMU()
{
    // Initialize 
    int handle = i2cOpen(0, I2C_ADDRESS, 0);
    SetI2C(handle);
}

void IMU::SetI2C(int newI2C){this->i2c = newI2C;}
int IMU::GetI2C(){return this->i2c;}

void IMU::PrintValues(){
    auto data = i2cReadByte(this->i2c);
    std::cout << "IMU Data: " << data << std::endl;
}

