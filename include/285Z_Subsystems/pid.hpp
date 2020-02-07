#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

extern double kP;
extern double kI;
extern double kD;

class PID {

  public:
    
  void calibrate();
  void turnAbsolute(int);
  void turnClockwise(int);

};
