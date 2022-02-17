/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       alstonliu                                                 */
/*    Created:      Wed Feb 19 2020                                           */
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
  // INERTIAL CALIBRATION
  Inertial.calibrate();
  do {
    wait(5);
  } while (Inertial.isCalibrating());

  Controller.Screen.clearScreen();
  Controller.Screen.setCursor(1, 1);
  Controller.Screen.print("Calibration Done");

  //selection
  AutonSelector();

  // PREAUTON
  task bgtr2(Timer2);
  task bCon(ControllerGUI);
  //task fuck(velocityPrint);
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
void autonomous(){
  //pidStrafe(-24, 80, 3000);
  red5();
  //AUTONOMOUS SELECTOR
 /* switch(AllianceColor){
    case 'R':{
      //RED 6
      if(auton == 6){
        red6();
        break;
      }
      //RED5
      else if(auton == 5){
        red5();
        break;
      }
    }
    case 'B':{
      //BLUE 6
      if(auton == 6){
        blue6();
        break;
      } 
      //BLUE 5
      else if(auton == 5){
        blue5();
        break;
      }
    }
    //NO AUTON SELECTED
    default:{
      
      break;
    }
  }
  wait(10); */
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
void opcontrol(){
  autonSelect = true;
  Brain.Screen.clearScreen();
  Brain.Screen.drawImageFromFile("Logo.png",0,0);
  Brain.Screen.drawImageFromFile("SolidworksLogo.png",270,30);
  resetAll();

  while(1){
    driveControl();
    clawControl();
    liftControl();
    wait(16);
  }
}

int main(){
  //Competition Callbacks for autonomous and drive control periods
  Competition.autonomous(autonomous);
  Competition.drivercontrol(opcontrol);

  pre_auton();
  //Prevent main from exiting with an infinite loop.
  while(1){
    wait(100); // Sleep task to prevent wasted resources. 
  }
}
