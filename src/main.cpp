#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
 
int main()
{
  // Always start the pigpio daemon before running this file
  FlightCont mainController;
  std::cout << "Pi number is: " << mainController.frontr->GetPi() << std::endl;
  mainController.frontr->SetSpeed(5);
  return 0;
}