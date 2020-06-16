#pragma once
#include <pigpio.h>
#include <pigpiod_if2.h>

class MotorCont 
{
    private:
        const unsigned int frequency = 50; // Should always be using a 50% duty cycle
        int motorPin;
    public:
        unsigned int throttle; // 0-255 for pwm 
        MotorCont(int motorPin);
        MotorCont();
        int SetSpeed(unsigned int throttle);
        int GetMotorPin();
        void SetMotorPin(int newMotorPin);
};