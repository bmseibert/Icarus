#pragma once

class IMU
{
    private:
        int i2c = 0; // returned by i2c open
    public:
        int XGyroOffset = 0;
        int YGyroOffset = 0;
        int ZGyroOffset = 0;
        int ZAccelOffset = 0;
        IMU(int& pi, const int& imu_sda, const int& imu_scl);
        void SetI2C(int& newI2C);
        int GetI2C();
};