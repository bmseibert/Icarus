#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
#include <thread>
#include <chrono>
 
int main()
{
  // Always start the pigpio daemon before running this file
  int val = gpioInitialise();
  std::cout << "Initailization val: " << val << std::endl;
  bool calibrate = false;
  char enter[10];
  gpioServo(23, 0);
  gpioSetMode(23, PI_OUTPUT);
  if (calibrate){
    gpioServo(23, 0);
    gpioServo(23, 2000); //set it to max value
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    gpioServo(23, 1000); // set it to the min value
    std::this_thread::sleep_for(std::chrono::milliseconds(12000));
    gpioServo(23, 0); // set it to 0
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    gpioServo(23, 1000); // Now it is armed
    std::cout << "PWM set up done" << std::endl;
  }
  else{
    gpioServo(23, 0); //set it to 0
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    gpioServo(23, 2000); // set it to the min value
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    gpioServo(23, 1000); // set it to 0
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
  }
  std::cout << "Running motor at quater speed" << std::endl;
  
  std::cout << "In Loop" << std::endl;
  gpioServo(23, 1200);
  
  // FlightCont mainController;
  // std::cout << "Pi number is: " << mainController.GetPi() << std::endl;
  // mainController.frontr->SetSpeed(25);
  // mainController.frontl->SetSpeed(30);
  // std::cout << "Speed of front right motor is: " << get_PWM_dutycycle(mainController.GetPi(), mainController.frontr->GetMotorPin()) << std::endl;
  // std::cout << "Speed of front left motor is: " << get_PWM_dutycycle(mainController.GetPi(), mainController.frontl->GetMotorPin()) << std::endl;
  std::cin.get();
  return 0;
}