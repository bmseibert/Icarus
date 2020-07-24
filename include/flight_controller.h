#pragma once
#include "motor_controller.h"
#include "imu.h"
#include "pigpio.h"
#include "pigpiod_if2.h"
#include "constants.h"
#include <thread>

enum Motor{frontr, frontl, backr, backl};

class FlightCont
{
    private:
    public:
        FlightCont();
        ~FlightCont();
        void ArmMotors();
        void Arm(const Motor type);
        MotorCont* frontr; // Motor controllers for the four flight motors
        MotorCont* frontl;
        MotorCont* backr;
        MotorCont* backl;
        IMU* imu;
};