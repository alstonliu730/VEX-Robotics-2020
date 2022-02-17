#include "macro.h"

void skillsCode(){
  //21SKILLS CODE
 
  // START UP
  startUp();

  // PUSHES BOTH CUBES OUT
  task bsg(first);
  //pidMove(11.5, 50,3000);
  StraightGyroMove(12.75,50,brake);
  wait(100);

  // uses preload to stack six
  SixStack1();

  // turns to move full stack to Goal Zone
  autoLift(7.5, 100);   
  wait(100);
  pidMove(-8.1, 30,3000);
  wait(100);

  task higher(lift3);
  pidTurn(111, 75, 3000);
  wait(50);
  pidMove(32,50,3000);
  wait(100);
  pidTurn(33,100,3000);
  
  wait(100);
  
  StraightMove(6, 30,1500,brake);
  wait(100);
  StraightMove(-8,30,brake);
  wait(100);
  //places stack down
  autoLift(-8,40,1500);
  pidTurn(-14,75,1000);

  StraightMove(7,30,1000,brake);
  wait(100);
  pidTurn(8,75,1000);
  StraightMove(6.5,30,1000,brake);
  autoLift(-2,25,800);
  task holding(holdDrive);
  clawGrab(2,-260);

  //============
  // TOWER 1
  //============

  //move near tower
  pidMove(-34,50,3000);
  //pidMove(-34,50,3000);
  wait(100);

  //turns to the tower
  clawGrab(2,30);
  wait(200);
  pidTurn(-135.75,75,3000);
    //pidTurn(-138, 75, 3000); //SUGGEST 136.5
  wait(200);

  //grabs the cube near tower
  pidMove(15.5,40,2000);
  clawGrab(2,320);

  //lift to tower
  StraightMove(-2,25,brake);
  autoLift(22,85);
  wait(200);
  pidTurn(5,75,500);
  StraightMove(8, 25,brake);
  wait(200);
  //drops cube on tower
  clawGrab(2,-250);
  wait(250);

  //goes back to original state
  StraightMove(-3.5,25,brake);

  clawGrab(3,50);
  autoLift(-22, 85,3000);
 
  //================
  // TOWER 2
  //===============
  //movement to second tower 
  pidMove(-35,50,2000);
  wait(100);
  
  //turn to tower
  clawGrab(3,-40);
  pidTurn(-90.25, 75, 3000);
  wait(100);
  //pidMove(27,50,3000);
  pidMove(23, 50, 2000);
  wait(200);
  //grabs cube in front of tower
  clawGrab(2, 300);
  StraightGyroMove(-3, 30,brake);

  autoLift(33, 85, 4000);
  wait(200);
  pidTurn(5,75,500);
  StraightGyroMove(7.5,25,brake);
  wait(200);
  clawGrab(2, -280);

  StraightGyroMove(-5, 25,brake);
  wait(100);

  autoLift(-33,100,2000);
  wait(100);
  //================================
  //      TOWER 3
  //================================
  
  StrafeMove(24,100,1500); //would not be strong enough
  wait(100);
  StrafeMove(-4.5,85,1000);
  wait(100);
  
  clawGrab(3,30);
    //StraightMove(56.5,85,brake);
  pidMove(56,85,3000);
  wait(200);

  pidTurn(90,75,3000);

  StraightMove(-9,50,1000,brake);
  wait(500);

  clawGrab(3,-50);
  //pidMove(52,85,3000);
  //task closing(closeIt);
  StraightGyroMove(55,85,3000,brake);
  wait(100);

  //grabs the cube in front of tower
  clawGrab(2,380);
  wait(100);

  StraightMove(-3,25,brake);
  wait(200);

  autoLift(22,85);
  StraightMove(6,20,brake);
  wait(100);

  clawGrab(2,-200);

  //================================
  //      TOWER 4
  //================================


  
}