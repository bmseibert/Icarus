#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
 
int main()
{
  // Always start the pigpio daemon before running this file
  FlightCont mainController;
  std::cout << mainController.frontr->GetPi() << std::endl;
  std::cout << "Hello World!" << std::endl;
  return 0;
}