#include <iostream>
#include "motor_controller.h"

MotorCont::MotorCont(int motorPin)
{
    std::cout << "Initializing Motor: " << motorPin << std::endl; 
    // Set pigpio mode to output
    gpioSetMode(motorPin, PI_OUTPUT);
    SetMotorPin(motorPin);
    this->throttle = 0;
    // To init esc, must send a zero signal first
    SetSpeed(0);
    std::cout << "Finished Initializing Motor: " << motorPin << std::endl; 
}

MotorCont::MotorCont(){}

// Getters and Setters for private attributes
int MotorCont::GetMotorPin(){return this->motorPin;}
void MotorCont::SetMotorPin(int newMotorPin){this->motorPin = newMotorPin;}

int MotorCont::SetSpeed(unsigned int throttle)
{
    this->throttle = throttle;
    std::cout << "Duty Cycle is: " << this->throttle << std::endl;
    // Set frequency to 50Hz and adjust dutycycle to change speed
    gpioSetPWMfrequency(GetMotorPin(), this->frequency);
    gpioPWM(GetMotorPin(), throttle);
    return 0;
}
