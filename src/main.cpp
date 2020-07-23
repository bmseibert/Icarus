#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
 
int main()
{
  FlightCont boss;
  boss.ArmMotors();
  std::cout << "Running motor at quater speed" << std::endl;
  boss.frontr->SetSpeed(1200);
  boss.frontl->SetSpeed(1200);
  boss.backr->SetSpeed(1200);
  boss.backl->SetSpeed(1200);
  std::cin.get();
  return 0;
}