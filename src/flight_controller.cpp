#include <iostream>
#include "flight_controller.h"
#include "pigpio.h"
#include "pigpiod_if2.h"
#include "constants.h"

FlightCont::FlightCont()
{
    // Connect to the pigpio daemon before anything (NULL uses default ip and port)
    int newPi = pigpio_start(NULL, NULL);
    SetPi(newPi);
    this->frontr = new MotorCont(newPi, MOTOR1);
    this->frontl = new MotorCont(newPi, MOTOR2);
    this->backr = new MotorCont(newPi, MOTOR3);
    this->backl = new MotorCont(newPi, MOTOR4);
    // Set the motorcontrollers to the correct pins
    // Initialize the IMU
}

int FlightCont::GetPi()
{
    return this->pi;
}

void FlightCont::SetPi(int& newPi)
{
    this->pi = newPi;
}

int FlightCont::InitGpio()
{
    // Must connect to the pigpio daemon
    int newPi = pigpio_start(NULL, NULL);
    SetPi(newPi);
    return 0;
}

int FlightCont::CleanUp()
{
    // Close pigpio resources
    pigpio_stop(this->pi);
    return 0;
}