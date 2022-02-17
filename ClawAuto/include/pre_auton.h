#include "config.h"

int T1 = 0;
int T3 = 0;

const float pi = M_PI;
const float GYRO_SCALE = 3.5;

int auton = 0;

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

float encRaw(motor motorname) { return motorname.rotation(rotationUnits::raw); }

float vel(motor motorname) {return motorname.velocity(velocityUnits::pct);}

float velRPM(motor motorname) {return motorname.velocity(velocityUnits::rpm);}

float velDPS(motor motorname) {return motorname.velocity(velocityUnits::dps);}

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
static float leftSpeed = 0;
static float rightSpeed = 0;
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
      Controller.Screen.print("");
  }
  return 0;
}

