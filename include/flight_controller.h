#pragma once
#include "motor_controller.h"
#include "imu.h"

class FlightCont
{
    private:
    public:
        FlightCont();
        ~FlightCont();
        void ArmMotors();
        MotorCont* frontr; // Motor controllers for the four flight motors
        MotorCont* frontl;
        MotorCont* backr;
        MotorCont* backl;
        IMU* imu;
};