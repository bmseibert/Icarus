#include <iostream>
#include "motor_controller.h"

MotorCont::MotorCont(int motorPin)
{
    std::cout << "Initializing Motor: " << motorPin << std::endl; 
    // Set pigpio mode to output
    gpioSetMode(motorPin, PI_OUTPUT);
    SetMotorPin(motorPin);
    this->pulseWidth = 0;
    // To init esc, must send a zero signal first
    SetSpeed(0);
    std::cout << "Finished Initializing Motor: " << motorPin << std::endl; 
}

MotorCont::MotorCont(){}

// Getters and Setters for private attributes
int MotorCont::GetMotorPin(){return this->motorPin;}
void MotorCont::SetMotorPin(int newMotorPin){this->motorPin = newMotorPin;}

int MotorCont::SetSpeed(unsigned int pulseWidth)
{
    this->pulseWidth = pulseWidth;
    gpioServo(this->motorPin, pulseWidth);
    return 0;
}

void MotorCont::Arm(){
    std::cout << "Arming Motor: " << this->motorPin << std::endl;
    SetSpeed(0);
    SetSpeed(0); //set pwm to 0
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    SetSpeed(2000); // set it to the max value
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    SetSpeed(1000); // set it to the minimum value
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::cout << "Motor " << this->motorPin << " armed" << std::endl;
}
