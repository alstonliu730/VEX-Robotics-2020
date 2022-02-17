/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       alstonliu                                                 */
/*    Created:      Sun Nov 24 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "auton.h"

using namespace std;
using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton() {
  // GYRO CALIBRATION
  Inertial.calibrate();
  do {
    wait(5);
  } while (Inertial.isCalibrating());
  Controller.Screen.clearScreen();
  Controller.Screen.setCursor(1, 1);
  Controller.Screen.print("Calibration Done");
 
  // PREAUTON
  task bgtr(Timer2);
  task printGyro(ControllerGUI);
  //task blah(encPrint);
  resetAll();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void autonomous() {
  //task ptsd()
  skillsCode();
  //pidTurn(90, 75, 3000);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void MecanumDrive() {
  int deadzone = 15;
  if (abs(ch1) > deadzone || abs(ch3) > deadzone ||
      abs(ch4) > deadzone + 20) // deadzone for controller
  {
    LeftTop.spin(directionType::fwd, ch3 + ch1 + ch4, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, ch3 + ch1 - ch4, velocityUnits::pct);
    RightTop.spin(directionType::fwd, ch3 - ch1 - ch4, velocityUnits::pct);
    RightBot.spin(directionType::fwd, ch3 - ch1 + ch4, velocityUnits::pct);
  } else if (bUp) {
    LeftTop.spin(directionType::fwd, 20, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, 20, velocityUnits::pct);
    RightTop.spin(directionType::fwd, 20, velocityUnits::pct);
    RightBot.spin(directionType::fwd, 20, velocityUnits::pct);
  } else {
    LeftTop.stop(brakeType::brake);
    LeftBot.stop(brakeType::brake);
    RightTop.stop(brakeType::brake);
    RightBot.stop(brakeType::brake);
  }
}

void lift() {
  if (bL1) {
    liftLeft.spin(directionType::fwd, 100, velocityUnits::pct);
    liftRight.spin(directionType::fwd, 100, velocityUnits::pct);
    liftSupport.spin(directionType::fwd, 100, velocityUnits::pct);
  } else if (bL2) {
    liftLeft.spin(directionType::rev, 75, velocityUnits::pct);
    liftRight.spin(directionType::rev, 75, velocityUnits::pct);
    liftSupport.spin(directionType::rev, 75, velocityUnits::pct);
  } else if (bX) {
    liftLeft.spin(directionType::rev, 20, velocityUnits::pct);
    liftRight.spin(directionType::rev, 20, velocityUnits::pct);
    liftSupport.spin(directionType::rev, 20, velocityUnits::pct);
  } else {
    liftLeft.stop(brakeType::hold);
    liftRight.stop(brakeType::hold);
    liftSupport.stop(brakeType::hold);
  }
}

void claw() {
  if (bR1) {
    clawMain.spin(directionType::fwd, 100, velocityUnits::pct);
  } else if (bR2) {
    clawMain.spin(directionType::rev, 100, velocityUnits::pct);
  } else {
    clawMain.stop(brakeType::hold);
  }
}

void opcontrol() {
  while (1) {
    MecanumDrive();
    claw();
    lift();
    wait(16);
  }
}

int main() {
  // Competition Callbacks for autonomous and drive control periods
  Competition.autonomous(autonomous);
  Competition.drivercontrol(opcontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (1) {
    wait(100); // Sleep the task to prevent wasted resources.
  }
}
