#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
 
int main()
{
  // Always start the pigpio daemon before running this file
  FlightCont mainController;
  std::cout << "Pi number is: " << mainController.GetPi() << std::endl;
  mainController.frontr->SetSpeed(25);
  mainController.frontl->SetSpeed(30);
  std::cout << "Speed of front right motor is: " << gpio_read(mainController.GetPi(), mainController.frontr->GetMotorPin()) << std::endl;
  std::cout << "Speed of front left motor is: " << gpio_read(mainController.GetPi(), mainController.frontl->GetMotorPin()) << std::endl;
  std::cin.get();
  return 0;
}