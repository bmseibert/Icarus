#pragma once
#include <pigpio.h>
#include <pigpiod_if2.h>
#include <thread>
#include <chrono>

class MotorCont 
{
    private:
        const unsigned int frequency = 50; // Should always be using a 50% duty cycle
        int motorPin;
    public:
        unsigned int pulseWidth; // 0-2000ms 
        MotorCont(int motorPin);
        MotorCont();
        int SetSpeed(unsigned int pulseWidth);
        int GetMotorPin();
        void SetMotorPin(int newMotorPin);
        void Arm();
};