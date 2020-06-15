#pragma once
#include <pigpio.h>
#include <pigpiod_if2.h>

class MotorCont 
{
    private:
        const unsigned int frequency = 50; // Should always be using a 50% duty cycle
        int pi; 
        int motorPin;
    public:
        int throttle;
        MotorCont(int pi, int motorPin);
        MotorCont();
        int SetSpeed(int throttle);
        int GetPi();
        void SetPi(int newPi);
        int GetMotorPin();
        void SetMotorPin(int newMotorPin);
};