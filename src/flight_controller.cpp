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
    // Set the motorcontrollers to the correct pins
    this->frontr = new MotorCont(newPi, MOTORFR);
    this->frontl = new MotorCont(newPi, MOTORFL);
    this->backr = new MotorCont(newPi, MOTORBR);
    this->backl = new MotorCont(newPi, MOTORBL);
    // Initialize the IMU
    this->imu = new IMU(newPi, IMU_SDA, IMU_SCL);
}

int FlightCont::GetPi()
{
    return this->pi;
}

void FlightCont::SetPi(int newPi)
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

FlightCont::~FlightCont(){
    delete this->frontl;
    delete this->frontr;
    delete this->backl;
    delete this->backr;
    delete this->imu;
}