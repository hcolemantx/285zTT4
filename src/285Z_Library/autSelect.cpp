#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"


void selectAuton(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){

  liftMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  double potVal = autonPot.get();
  if(potVal >= 0 && potVal < 819){
    //shortGoalSixRed(chassis, slow, fast);
    sgFiveRed(slow, medium, fast);
  }
  if(potVal >= 820 && potVal <= 1638){
    sgFiveBlue(slow, medium, fast);
  }
  if(potVal >= 1639 && potVal <= 2457){
    lgRed(slow, medium, fast);
  }
  if(potVal >= 2458 && potVal <= 3276){
    lgBlue(slow, medium, fast);
  }
  if(potVal >= 3277 && potVal <= 4096){
    skills(slow, medium, fast);
  }

}

//will write to the screen to say the auton
void displayAuton(){
  double potVal = autonPot.get();
  if(potVal >= 0 && potVal < 819){
    lv_aut_display("RED SHORT GOAL");
  }
  if(potVal >= 820 && potVal <= 1638){
    lv_aut_display("BLUE SHORT GOAL");
  }
  if(potVal >= 1639 && potVal <= 2457){
    lv_aut_display("RED LONG GOAL");
  }
  if(potVal >= 2458 && potVal <= 3276){
    lv_aut_display("BLUE LONG GOAL");
  }
  if(potVal >= 3277 && potVal <= 4096){
    lv_aut_display("SKILLS");
  }
}
