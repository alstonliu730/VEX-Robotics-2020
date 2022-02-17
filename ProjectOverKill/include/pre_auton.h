#include "config.h"

int T3 = 0;

const float pi = M_PI;
const float GYRO_SCALE = 3.5;
bool autonSelect;

int auton = 0;

float botVel = 0;
float avgError = 0;
float pidTIMEOUT = 3000;
float PID_MOTOR_MAX = 100;
float PID_MOTOR_MIN = -100;

void resetEncoder() {
  LeftTop.resetRotation();
  RightTop.resetRotation();
  LeftBot.resetRotation();
  RightBot.resetRotation();
}

void resetLift() {
  liftLeft.resetRotation();
  liftRight.resetRotation();
  liftSupport.resetRotation();
}

void resetClaw() { clawMain.resetRotation(); }

void resetAll() {
  resetEncoder();
  resetLift();
  resetClaw();
}

// RETURN MOTOR VALUES
float enc(motor motorname) { return motorname.rotation(rotationUnits::deg); }

float encRev(motor motorname) {return motorname.rotation(rotationUnits::rev); }

float encRaw(motor motorname) { return motorname.rotation(rotationUnits::raw); }

float vel(motor motorname) {return motorname.velocity(velocityUnits::pct); }

float velRPM(motor motorname) {return motorname.velocity(velocityUnits::rpm); }

float velDPS(motor motorname) {return motorname.velocity(velocityUnits::dps); }

float pos(motor motorname) {return motorname.position(deg); }

float inchToTicks(float dist) {return (dist * 330/ (4.0 * pi)); }
//0 == <
//1 == >
bool compareEnc(motor motor1, motor motor2, int mode){
  if(mode == 0){
    return fabs(enc(motor1)) < fabs(enc(motor2));
  }
  else {
    return fabs(enc(motor1)) > fabs(enc(motor2));
  }
}

void rightDrive(double speed_right) {
  RightTop.spin(directionType::fwd, speed_right, velocityUnits::pct);
  RightBot.spin(directionType::fwd, speed_right, velocityUnits::pct);
}

void leftDrive(double speed_left) {
  LeftTop.spin(directionType::fwd, speed_left, velocityUnits::pct);
  LeftBot.spin(directionType::fwd, speed_left, velocityUnits::pct);
}

//EXTRA MATH
float average(float num1, float num2){
  return (num1 + num2)/2.0;
}

// TESTING SLEW DRIVE MODE
const float accel_step = 10;
const float deccel_step = 10;

/*
static float leftSpeed = 0;
static float rightSpeed = 0;
*/

static float leftSpeed = average(vel(LeftTop), vel(LeftBot));
static float rightSpeed = average(vel(RightTop), vel(RightBot));

void rightSlew(float targetSpeed) {
  float step;
  if (fabs(rightSpeed) < fabs(targetSpeed)) {
    step = accel_step;
  } else {
    step = deccel_step;
  }

  if (targetSpeed > rightSpeed + step) {
    rightSpeed += step;
  } else if (targetSpeed < rightSpeed - step) {
    rightSpeed -= step;
  } else {
    rightSpeed = targetSpeed;
  }

  rightDrive(rightSpeed);
}

void leftSlew(float targetSpeed) {
  float step;
  if (fabs(leftSpeed) < fabs(targetSpeed)) {
    step = accel_step;
  } else {
    step = deccel_step;
  }

  if (targetSpeed > leftSpeed + step) {
    leftSpeed += step;
  } else if (targetSpeed < leftSpeed - step) {
    leftSpeed -= step;
  } else {
    leftSpeed = targetSpeed;
  }

  leftDrive(leftSpeed);
}

// STOPS ALL DRIVETRAIN MOVEMENT BY A BRAKETYPE
void StopMove(brakeType stopType) {
  RightTop.stop(stopType);
  RightBot.stop(stopType);
  LeftBot.stop(stopType);
  LeftTop.stop(stopType);
}

// task control
int Timer2() {
  while (1) {
    T3 += 1;
    wait(1);
  }
}

//480 x 272 
//Need animation for autons
void AutonSelector(){

  autonSelect = true;
  char TrackColor;
  int autoTemp;
  Brain.Screen.clearScreen(color::black);
  Brain.Screen.drawImageFromFile("GameField.png",210,0);
  int selection = 0;
  int autoNum = 4;

  //BOXES DIMENSION
  int height = 40;
  int width = 90;

  while(selection < 6){
    Brain.Screen.setPenWidth(1);
    Brain.Screen.setPenColor(color::black);

    //RED Auton
    int redX = 30;
    
      //RED5
      if(xPos > redX && xPos < redX + width && yPos > 20 && yPos < 20 + height){
        selection = 1; 
      }

      //RED6
      else if(xPos > redX && xPos < redX + width && yPos > 80 && yPos < 80 + height){
        selection = 3;
      }

    //BLUE Auton
    int blueX = 150;
    
      //BLUE5
      if(xPos > blueX && xPos < blueX + width && yPos > 20 && yPos < 20 + height){
        selection = 2;
      }

      //BLUE6
      else if(xPos > blueX && xPos < blueX + width && yPos > 80 && yPos < 80 + height){
        selection = 4;
      }

    //SELECTION
    int selectX = 90;

      if(selection == 5 && Brain.Screen.pressing() == 0){
        selection = 6;
      }else if((bA && selection > 0) || (xPos > selectX && xPos < selectX + 120 && yPos > 150 && yPos < 150 + height && selection != 0)){
        selection = 5;
      }
      
    //CONTROLLER SELECTIING
    if(bRight && selection < autoNum){
      selection ++;
    } else if(bLeft && selection > 1){
      selection --;
    }

    //SELECTING GRAPHICS - HIGHLIGHTS THE BOXES

    if(selection == 1){ //R5
      TrackColor = 'R';
      autoTemp = 5;
      Brain.Screen.drawRectangle(redX - 3, 17, width + 6, height + 6, color::green);
      Brain.Screen.drawRectangle(redX - 3, 77, width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(blueX - 3, 17,width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(blueX - 3, 77,width + 6, height + 6, color::black);
    } 
    
    else if (selection == 3){ //R6
      TrackColor = 'R';
      autoTemp = 6;
      Brain.Screen.drawRectangle(redX - 3, 17, width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(redX - 3, 77, width + 6, height + 6, color::green);
      Brain.Screen.drawRectangle(blueX - 3, 17,width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(blueX - 3, 77,width + 6, height + 6, color::black);
    }
        
    else if(selection == 2){ //B5
      TrackColor = 'B';
      autoTemp = 5;
      Brain.Screen.drawRectangle(redX - 3, 17, width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(redX - 3, 77, width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(blueX - 3, 17,width + 6, height + 6, color::green);
      Brain.Screen.drawRectangle(blueX - 3, 77,width + 6, height + 6, color::black);
    }

    else if(selection == 4){ //B6
      TrackColor = 'B';
      autoTemp = 6;
      Brain.Screen.drawRectangle(redX - 3, 17, width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(redX - 3, 77, width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(blueX - 3, 17,width + 6, height + 6, color::black);
      Brain.Screen.drawRectangle(blueX - 3, 77,width + 6, height + 6, color::green);
    }
        
    else if(selection == 5) //SELECT
    {
      Brain.Screen.drawRectangle(selectX - 3, 147, width + 6, height + 6, color::green);
    }
    
    //DRAWING BOXES
    Brain.Screen.drawRectangle(redX,20,width,height,color::red); //R5
    Brain.Screen.drawRectangle(redX,80,width,height,color::red); //R6
    Brain.Screen.drawRectangle(blueX,20,width,height,color::blue); //B5
    Brain.Screen.drawRectangle(blueX,80,width,height,color::blue); //B6
    Brain.Screen.drawRectangle(selectX, 150, width, height,color::white); //SELECT
    
    //TEXT
    Brain.Screen.setPenWidth(10);
      //COLOR BOXES
    Brain.Screen.setPenColor(color::white);
    Brain.Screen.printAt(redX + 25, 45, false, "RED 5");
    Brain.Screen.printAt(redX + 25, 105,false, "RED 6");
    Brain.Screen.printAt(blueX + 19, 45, false, "BLUE 5");
    Brain.Screen.printAt(blueX + 19, 105,false, "BLUE 6");
      //SELECT BUTTON
    Brain.Screen.setPenColor(color::black);
    Brain.Screen.printAt(selectX + 15, 175, false, "SELECT");

    AllianceColor = TrackColor;
    auton = autoTemp;
    wait(100);
  }
  //PRINT AUTON INFORMATION
  Brain.Screen.clearScreen();
  // PRINTING TEAM COLOR!
  if (AllianceColor == 'B') {
    Brain.Screen.drawRectangle(30, 20, 110, 40, color::blue);
    Brain.Screen.setPenWidth(10);
    Brain.Screen.setPenColor(color::white);
    Brain.Screen.printAt(70, 45, false, "BLUE");

  } else {
    Brain.Screen.drawRectangle(30, 20, 110, 40, color::red);
    Brain.Screen.setPenWidth(10);
    Brain.Screen.setPenColor(color::white);
    Brain.Screen.printAt(70, 45, false, "RED");
  }
  
  Brain.Screen.setPenWidth(1);
  Brain.Screen.setPenColor(color::black);
  if (AllianceColor == 'B'){
    Brain.Screen.drawRectangle(30, 100, 110, 40, color::blue);
  }else{
    Brain.Screen.drawRectangle(30, 100, 110, 40, color::red);
  }
  Brain.Screen.setPenWidth(10);
  Brain.Screen.setPenColor(color::white);

  if (auton == 5) {
    Brain.Screen.printAt(70, 125, false, "5 PTS");
  } else if (auton == 6) {
    Brain.Screen.printAt(70, 125, false, "6 PTS");
  } else {
    Brain.Screen.printAt(70, 125, false, "None");
  }
  //PRINT AUTON PATH ON IMAGE
  Brain.Screen.drawImageFromFile("GameField.png",210,0);
  autonSelect = false;
  wait(100);
}

int ControllerGUI(){
  Controller.Screen.clearScreen();
  while(1){
    Controller.Screen.setCursor(1,1);
      Controller.Screen.print("Battery: "); 
      Controller.Screen.print(Brain.Battery.capacity(percentUnits::pct)); 
    Controller.Screen.setCursor(2,1);
      Controller.Screen.print("Rotation: ");
      Controller.Screen.print(Inertial.rotation());
    Controller.Screen.setCursor(3,1);
      Controller.Screen.print("Team: ");
      if(AllianceColor == 'B'){
        Controller.Screen.print("B");
      }
      if(AllianceColor == 'R'){
        Controller.Screen.print("R");
      }
      Controller.Screen.print(" Auton: ");
      Controller.Screen.print(auton);
    wait(10);
  }
  return 0;
}

int velocityPrint(){
  Controller.Screen.clearScreen();
  while(1){
    Controller.Screen.setCursor(1,1);
      Controller.Screen.print("LB: ");
      Controller.Screen.print(LeftBot.velocity(pct));
      Controller.Screen.print("   RB: ");
      Controller.Screen.print(RightBot.velocity(pct));
    Controller.Screen.setCursor(2,1);
      Controller.Screen.print("LT: ");
      Controller.Screen.print(LeftTop.velocity(pct));
      Controller.Screen.print("   RT: ");
      Controller.Screen.print(RightTop.velocity(pct));
    wait(10);
  }
  return 0;
}