#include <iostream>
#include "flight_controller.h"
#include "motor_controller.h"
 
int main()
{
  FlightCont boss;
  bool calibrate = false;
  if (calibrate){
    gpioServo(17, 0);
    gpioServo(17, 2000); //set it to max value
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    gpioServo(17, 1000); // set it to the min value
    std::this_thread::sleep_for(std::chrono::milliseconds(12000));
    gpioServo(17, 0); // set it to 0
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    gpioServo(17, 1000); // Now it is armed
    std::cout << "PWM set up done" << std::endl;
  }
  else{
    boss.ArmMotors();
  }
  std::cout << "Running motor at quater speed" << std::endl;
  boss.frontr->SetSpeed(1200);
  std::cin.get();
  return 0;
}