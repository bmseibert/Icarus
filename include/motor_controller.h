#pragma once
#include <pigpio.h>
#include <pigpiod_if2.h>

class MotorCont 
{
    private:
        const unsigned int frequency = 50; // Should always be using a  
        int pi; 
        int motorPin;
    public:
        int throttle;
        MotorCont(int& pi, const int& motorPin);
        MotorCont();
        int SetSpeed(const int& throttle);
        int GetPi();
        void SetPi(int& newPi);
        int GetMotorPin();
        void SetMotorPin(const int& newMotorPin);
};