#include "macro.h"

void red6(){
  // START UP
  startUp();

  // PUSHES BOTH CUBES OUT
  task firstStep(first);
  StraightGyroMove(12.25, 60,brake);

  // uses preload to stack six
  SixStack();

  // turns to level with the wall
  autoLift(5, 100);

  /* task holdIt(holdCubes);
  //StraightMove(-5.5, 85);
  StraightMove(-5.25,50,coast);
  holdIt.stop(); */
  wait(150);
  task holdIt2(holdCubes);
  pidTurn(142.5, 100, 2500);
  holdIt2.stop();
  wait(100);
  pidMove(24,85,3000);
  wait(100);
  curvedMove(36, 90, 70, 'R');

  autoLift(-4,25,1000);
  wait(200);
  clawGrab(2,-240);

  StraightMove(-20,50,brake);
}

void red5(){
  //5PT RED
  startUp(); //forward and deploy
  
  StraightGyroMove(20.65,50,brake);//to first cube
  //pidMove(20.25,55,3000);
  wait(200);
        
  first3();//drive and pick up first cube

  wait(100);

  fiveStack();  

  autoLift(5,100);
  wait(100);

  //StraightGyroMove(-12,60,brake);
  pidMove(-12,65,3000);
  wait(100);
  
  pidTurn(135,75,3000);

  wait(200);

  //StraightGyroMove(20,65,brake);
  pidMove(20,65,3000);
  wait(100);

  StrafeMove(16,90,3000);
  wait(100);

  StraightMove(16,65,2000,brake);
  autoLift(-2.5,25);

  wait(250);
  clawGrab(2,-300);
  wait(100);
  StraightMove(-20,85,brake);
}

void blue6(){
  // START UP
  startUp();
  wait(100);
  // PUSHES BOTH CUBES OUT
  task firstStep(first);
  StraightGyroMove(12.5, 60,brake);

  // uses preload to stack six
  SixStack();

  // turns to level with the wall
  autoLift(5, 75);

  /* task holdIt(holdCubes);
  StraightMove(-5,50,brake);
  holdIt.stop(); */
  wait(150);
  task holdIt2(holdCubes);
  pidTurn(-142.5,100,2500);
  holdIt2.stop();
  wait(100);

  StraightGyroMove(18,85,coast);
  wait(100);
  curvedMove(24, 85, 50, 'L');
  /* pidTurn(-122.5, 100, 2500);
  holdIt2.stop();
  wait(100);
  StraightGyroMove(29,85,coast);
  wait(100); */
  autoLift(-4,25,1000);
  wait(250);
  clawGrab(2,-240);

  StraightMove(-20,50,brake);
}

void blue5(){
  //5PT Blue
  startUp();
  
  StraightGyroMove(21,50,brake);      
  wait(100);  

  first3();

  wait(100);
  
  fiveStack();        

  autoLift(5,100);
  wait(100);

  pidMove(-12,70,3000);
  wait(100);

  pidTurn(-130,75,3000);

  wait(100);

  //StraightGyroMove(19.5,65,brake);
  pidMove(22,75,3000);
  wait(100);

  StrafeMove(-18,90,3000);
  wait(100);

  StraightMove(16,75,2000,brake);
  autoLift(-2.5,25);

  wait(150);
  clawGrab(2,-300);
  wait(100);
  StraightMove(-20,100,brake);      
}