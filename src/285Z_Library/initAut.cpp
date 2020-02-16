#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"

void stackDeploy(std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  Tray angler;
  angler.moveToUp(false);
  pros::Task::delay(1500);
  intake.moveRelative(-300, 110);//outtake
}
