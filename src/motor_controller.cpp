#include <iostream>
#include "motor_controller.h"

MotorCont::MotorCont(int pi, int motorPin)
{
    std::cout << "Initializing Motor: " << motorPin << std::endl; 
    // Set pigpio mode to output
    set_mode(pi, motorPin, PI_OUTPUT);
    SetPi(pi);
    SetMotorPin(motorPin);
    this->throttle = 0;
    // To init esc, must send a zero signal first
    SetSpeed(0);
    std::cout << "Finished Initializing Motor: " << motorPin << std::endl; 
}

MotorCont::MotorCont(){}

// Getters and Setters for private attributes
int MotorCont::GetPi(){return this->pi;}
void MotorCont::SetPi(int newPi){this->pi = newPi;}
int MotorCont::GetMotorPin(){return this->motorPin;}
void MotorCont::SetMotorPin(int newMotorPin){this->motorPin = newMotorPin;}

int MotorCont::SetSpeed(int throttle)
{
    // Set the range from 0-100 to 0-255 for dutycycle
    double duty = 255*(throttle/100);
    this->throttle = throttle;
    std::cout << "Duty Cycle is: " << duty << std::endl;
    // Set frequency to 50Hz and adjust dutycycle to change speed
    set_PWM_frequency(GetPi(), GetMotorPin(), this->frequency);
    set_PWM_dutycycle(GetPi(), GetMotorPin(), duty);
    return 0;
}
