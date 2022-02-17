#include "claw.h"

//-------------------
// MACRO FUNCTIONS
//-------------------
int first() {
  autoLift(-4.75, 75,750);
  return 1;
}
int first2() {
  autoLift(-4.75, 40,1000);
  return 1;
}
int moveAbit(){
  StraightMove(1,30,brake);
  return 1;
}

int first3(){
  autoLift(-4.75,82,2000);
  clawGrab(2,400);
  return 1;
}
int lift4() {
  autoLift(25.5, 100,2000);
  return 1;
}
int holdCubes() {
  clawGrab(2, 70);
  return 1;
}
int lift3() {
  autoLift(3, 100);
  return 1;
}
int holdDrive(){
  StopMove(hold);
  return 1;
}
void startUp() {
  clawMain.setBrake(hold);

  autoLift(3.5, 100);
  wait(10);
  clawGrab(3, 60);
}

void stackPreload() {

  // grabs preload cube
  clawGrab(2, 380);
  autoLift(8.75, 100);

  // moves to second preload
  StraightMove(6, 30,brake);
  wait(10);

  // stacks preload on top of second cube
  autoLift(-2.5, 25,500);
  wait(10);
  clawGrab(2, -215);
  wait(10);

}
void stackPreload1() {

  // grabs preload cube
  clawGrab(2, 380);
  autoLift(8.75, 100);

  // moves to second preload
  pidMove(7, 30,3000);
  wait(10);

  // stacks preload on top of second cube
  autoLift(-2.5, 25,500);
  wait(10);
  clawGrab(2, -215);
  wait(10);

}
void SixStack() {
  // Stack Preload on to first cube
  stackPreload1();

  // grabs both cubes
  autoLift(-5.5, 50, 500);
  wait(10);
  clawGrab(2, 380);

  // goes to 4 stack while lifting up
  task fourStack(lift4);
  StraightMove(14.25, 13.15,brake);
  autoLift(-1.6, 25);

  // places 2 cube on 4 stack
  clawGrab(2, -355);
  StraightMove(-1, 50,brake); // Backs out so that the claw doesn't hit the stack
  wait(10);

  // prepares to grab all six
  autoLift(-24.5, 100, 1250);
  StraightMove(1.5,5,brake); // goes back to grab stack
  clawGrab(2, 380);

  fourStack.stop();
}

void fiveStack(){
  // goes to 4 stack while lifting up
  task fourStack(lift4);
  StraightMove(12.5, 13.5,brake);
  wait(10);
  autoLift(-2.3, 25);

  // places 2 cube on 4 stack
  clawGrab(2, -280);
  StraightMove(-1, 50,brake); // Backs out so that the claw doesn't hit the stack
  wait(10);

  // prepares to grab all six
  autoLift(-24.5, 100, 1250);
  StraightMove(2, 5,brake);// goes back to grab stack
  clawGrab(2, 340);

  fourStack.stop();
}

int move3(){
  StraightMove(3.5,57,brake);
  return 1;
}

int drop3(){
  autoLift(-3.75,25,1000);
  return 1;
}
int openIt(){
  clawGrab(2,-50);
  return 1;
}

int closeIt(){
  clawGrab(2,30);
  return 1;
}
