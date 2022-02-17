/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
brain Brain;
controller Controller = controller();

//Drive Train
motor LeftTop = motor(PORT4);
motor LeftBot = motor(PORT6);
motor RightTop = motor(PORT3,true);
motor RightBot = motor(PORT5,true);

//Lift
motor liftLeft = motor(PORT18, ratio36_1, true);
motor liftRight = motor(PORT8, ratio36_1);
motor liftSupport = motor(PORT7, ratio36_1, true);

//claw
motor clawMain = motor(PORT1, ratio36_1, true);

//SENSORS
inertial Inertial = inertial(PORT11);

//add potentiameter for precision code on the claw, left motor, and right motor for lifts...

char AllianceColor;

#define bL2  Controller.ButtonL2.pressing()
#define bL1 Controller.ButtonL1.pressing()
#define bA  Controller.ButtonA.pressing()
#define bR2  Controller.ButtonR2.pressing()
#define bR1  Controller.ButtonR1.pressing()
#define bB  Controller.ButtonB.pressing()
#define bX  Controller.ButtonX.pressing()
#define bY  Controller.ButtonY.pressing()
#define bLeft Controller.ButtonLeft.pressing()
#define bRight  Controller.ButtonRight.pressing()
#define bUp  Controller.ButtonUp.pressing()
#define bDown  Controller.ButtonDown.pressing()
#define ch3  Controller.Axis3.position(percentUnits::pct)
#define ch4  Controller.Axis4.position(percentUnits::pct)
#define ch1  Controller.Axis1.position(percentUnits::pct)
#define ch2  Controller.Axis2.position(percentUnits::pct)
#define wait task::sleep
#define xPos Brain.Screen.xPosition()
#define yPos Brain.Screen.yPosition()

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)