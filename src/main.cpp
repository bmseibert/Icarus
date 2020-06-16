#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
 
int main()
{
  // Always start the pigpio daemon before running this file
  int val = gpioInitialise();
  std::cout << "Initailization val: " << val << std::endl;
  gpioSetMode(17, PI_OUTPUT);
  gpioSetPWMfrequency(17, 30000);
  gpioPWM(17, 0);
  gpioPWM(17, 255);
  gpioPWM(17, 50);
  std::cout << "PWM set up done" << std::endl;
  // FlightCont mainController;
  // std::cout << "Pi number is: " << mainController.GetPi() << std::endl;
  // mainController.frontr->SetSpeed(25);
  // mainController.frontl->SetSpeed(30);
  // std::cout << "Speed of front right motor is: " << get_PWM_dutycycle(mainController.GetPi(), mainController.frontr->GetMotorPin()) << std::endl;
  // std::cout << "Speed of front left motor is: " << get_PWM_dutycycle(mainController.GetPi(), mainController.frontl->GetMotorPin()) << std::endl;
  std::cin.get();
  return 0;
}