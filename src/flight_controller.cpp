#include <iostream>
#include "flight_controller.h"


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
    this->imu = new IMU();
}

// This function is necessary for Threading 
void Arm(MotorCont* motor){
    motor->Arm();
};

void FlightCont::ArmMotors(){
    // These functions are threaded to cut down on the time spent waiting for arming
    std::thread frontrThead(Arm, this->frontr);
    std::thread frontlThead(Arm, this->frontl);
    std::thread backrThead(Arm, this->backr);
    std::thread backlThead(Arm, this->backl);
    frontrThead.join();
    frontlThead.join();
    backrThead.join();
    backlThead.join();
    std::cout << "All motors Armed" << std::endl;
}

FlightCont::~FlightCont(){
    delete this->frontl;
    delete this->frontr;
    delete this->backl;
    delete this->backr;
    delete this->imu;
}