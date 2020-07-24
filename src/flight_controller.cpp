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

// I think I need this function to thread the arming function
void FlightCont::Arm(const Motor type){
    switch (type)
    {
    case Motor::frontr:
        this->frontr->Arm();
        break;
    case Motor::frontl:
        this->frontl->Arm();
        break;
    case Motor::backr:
        this->backr->Arm();
        break;
    case Motor::backl:
        this->backl->Arm();
        break;
    }
};

void FlightCont::ArmMotors(){
    // Thread these operations
    std::thread frontrThead(Arm, Motor::frontr);
    std::thread frontlThead(Arm, Motor::frontl);
    std::thread backrThead(Arm, Motor::backr);
    std::thread backlThead(Arm, Motor::backl);
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