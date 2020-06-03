#pragma once
#include "motor_controller.h"

class FlightCont
{
    private:
        int pi; //Returned from pigpio library, used for starting and stoping daemon
    public:
        FlightCont();
        void SetPi(int& newPi);
        int GetPi();
        int InitGpio();
        int CleanUp();
        MotorCont* frontr; // Motor controllers for the four flight motors
        MotorCont* frontl;
        MotorCont* backr;
        MotorCont* backl;
};