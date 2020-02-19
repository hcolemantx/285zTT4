#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"


//*****************************   RED: FIVE CUBES    **********************//
void sgSixRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;
  lift.deploy();

  intake.moveVelocity(200);
  //************** INIT PATHS *******************//
  move(slow, 3.3_ft, fwd); //gets line of cubes
  turn(350);

  move(medium, 0.85_ft, fwd);
  move(fast, 2.0_ft, bwd);
  turn(168);

  move(slow, 1.5_ft, fwd);

  intake.moveVelocity(0);

  autoStackDeploy(1400);

  intake.moveVelocity(-120);
  move(fast, 1_ft, bwd);
  angler.moveToDown(false);
}

//******************************   RED: NINE CUBES   ****************************//
void sgNineRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  Tray angler;
  Lift lift;

  lift.deploy();

  intake.moveVelocity(200);

  move(fast, 3.20_ft, fwd);
  turn(330);

  move(fast, 3.20_ft, bwd);
  turn(0);

  move(fast, 3.1_ft, fwd);

  move(fast, 2_ft, bwd);
  intake.moveVelocity(0);
  turn(145);

  move(slow, 1.3_ft, fwd);

  autoStackDeploy(1400);

  intake.moveVelocity(-120);
  move(fast, 1_ft, bwd);
  angler.moveToDown(false);
}

//************************   RED: LONG GOAL   ****************************//
void lgRed(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast){
  Tray angler;
  Lift lift;

  move(fast, 1.9_ft, fwd);
  turn(98);

  move(medium, 2.7_ft, fwd);
  move(fast, 2.4_ft, bwd);
  turn(240);

  move(slow, 1.05_ft, fwd);
  autoStackDeploy(1400);

  move(fast, 1.3_ft, bwd);
  angler.moveToDown(false);
}
