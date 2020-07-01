#include <iostream>
#include "flight_controller.h"
#include "pigpio.h"
#include "pigpiod_if2.h"
#include "constants.h"

FlightCont::FlightCont()
{
    // Must initialize the gpio library 
    int val = gpioInitialise();
    std::cout << "Initailization val: " << val << std::endl;
    // Set the motorcontrollers to the correct pins
    this->frontr = new MotorCont(MOTORFR);
    this->frontl = new MotorCont(MOTORFL);
    this->backr = new MotorCont(MOTORBR);
    this->backl = new MotorCont(MOTORBL);
    // Initialize the IMU
    this->imu = new IMU(IMU_SDA, IMU_SCL);
}

void FlightCont::ArmMotors(){
    // Thread these operations
    this->frontr->Arm();
    this->frontl->Arm();
    this->backr->Arm();
    this->backl->Arm();
    std::cout << "All motors Armed" << std::endl;
}

FlightCont::~FlightCont(){
    delete this->frontl;
    delete this->frontr;
    delete this->backl;
    delete this->backr;
    delete this->imu;
}