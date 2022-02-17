#include "pre_auton.h"

/*
************************
|    AUTONOMOUS        |
************************ */

void StraightMove(float dist, float speed,brakeType stopType) {
  resetEncoder();

  float dir = 1;
  if (dist < 0) {
    dir = -1;
  }
  float FWDCount = fabs(dist * 330 / (4.0 * pi));

  while (fabs(enc(LeftTop)) < FWDCount) {
    if (fabs(enc(LeftTop)) < fabs((enc(RightTop)))) {
      RightTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
    }
    if (fabs(enc(LeftTop)) > fabs(enc(RightTop))) {
      RightTop.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    }
    RightTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    LeftTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    RightBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    wait(16);
  }
  StopMove(stopType);
}

void StraightMove(float dist, float speed, float timeout, brakeType stopType) {
  resetEncoder();
  float dir = 1;
  if (dist < 0) {
    dir = -1;
  }
  float FWDCount = fabs(dist * 330 / (4.0 * pi));
  T3 = 0;
  while (fabs(enc(LeftTop)) < FWDCount && T3 < timeout) {
    if (fabs(enc(LeftTop)) < fabs((enc(RightTop)))) {
      RightTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
    }
    if (fabs(enc(LeftTop)) > fabs(enc(RightTop))) {
      RightTop.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, (speed + 10) * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    }
    RightTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    LeftTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    RightBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    wait(16);
  }
  StopMove(stopType);
}

void StraightGyroMove(float dist, float speed, brakeType stopType) {
  resetEncoder();
  Inertial.resetRotation();

  float dir = 1;
  if (dist < 0) {
    dir = -1;
  }
  float FWDCount = fabs(dist * 330 / (4.0 * pi));

  while (fabs(enc(LeftTop)) < FWDCount && fabs(enc(RightTop)) < FWDCount) {
    if (fabs(enc(LeftTop)) < fabs((enc(RightTop)))) {
      RightTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
    }
    if (fabs(enc(LeftTop)) > fabs(enc(RightTop))) {
      RightTop.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    }
    RightTop.spin(directionType::fwd, (speed + dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    LeftTop.spin(directionType::fwd, (speed - dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    RightBot.spin(directionType::fwd, (speed + dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, (speed - dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    wait(16);
  }
  wait(10);
  StopMove(stopType);
}

void StraightGyroMove(float dist, float speed, float timeout,brakeType stopType) {
  resetEncoder();
  Inertial.resetRotation();

  float dir = 1;
  if (dist < 0) {
    dir = -1;
  }
  float FWDCount = fabs(dist * 330 / (4.0 * pi));
  T3 = 0;
  while (fabs(enc(LeftTop)) < FWDCount && fabs(enc(RightTop)) < FWDCount && T3 < timeout)  {
    if (fabs(enc(LeftTop)) < fabs((enc(RightTop)))) {
      RightTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
    }
    if (fabs(enc(LeftTop)) > fabs(enc(RightTop))) {
      RightTop.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, speed * dir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, (speed + 5) * dir, velocityUnits::pct);
      LeftBot.spin(directionType::fwd, speed * dir, velocityUnits::pct);
    }
    RightTop.spin(directionType::fwd, (speed + dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    LeftTop.spin(directionType::fwd, (speed - dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    RightBot.spin(directionType::fwd, (speed + dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, (speed - dir * GYRO_SCALE * Inertial.rotation()) * dir, velocityUnits::pct);
    wait(16);
  }
  wait(10);
  StopMove(stopType);
}

void pidMove(float dist, float speed, float timeout){
  resetEncoder();
  Brain.resetTimer();
  //float kp = 0.38, ki = 0.005, kd = 0.97;
  float kp = 48, ki = 0, kd = 37;
  float kp_c = 330;
  
  float speedLimit = speed * 120;

  float errorL,errorR;
  float totalErrorL = 0, totalErrorR = 0;
  float prevErrorL = 0,prevErrorR = 0;
  float leftSpeed, rightSpeed; 
  float error;
  float integralActiveZone = inchToTicks(1);

  float dir = 1;
  if (dist < 0){
    dir = -1;
  }

  float desired = fabs(dist * 350/ (4.0 * pi));

  T3 = 0;

  while(T3 < timeout){

    //PROPORTIONAL
    errorL = desired - average(fabs(enc(LeftTop)), fabs(enc(LeftBot))); 
    errorR = desired - average(fabs(enc(RightTop)), fabs(enc(RightBot)));
    
    float proportionL = kp * errorL;
    float proportionR = kp * errorR;

    //INTEGRAL
    if(fabs(errorL) < integralActiveZone && errorL != 0 && T3 > 0){totalErrorL += errorL;}
    else {totalErrorL = 0;}

    if(fabs(errorR) < integralActiveZone && errorR != 0 && T3 > 0){totalErrorR += errorR;}
    else {totalErrorR = 0;}

    float integralL =  ki * totalErrorL;
    float integralR = ki * totalErrorR;

    //DERIVATIVE
    float derivativeL = kd * (errorL - prevErrorL);
    prevErrorL = errorL;

    float derivativeR = kd * (errorR - prevErrorR);
    prevErrorR = errorR;
    
    //HARD LIMIT FOR DERIVATIVE
    if(errorL == 0){
      derivativeL = 0;
    }
    if(errorR == 0){
      derivativeR = 0;
    }

    //CALCULATE SPEED
    leftSpeed = (proportionL + integralL + derivativeL); 
    rightSpeed = (proportionR + integralR + derivativeR);

    //HARD LIMIT FOR SPEED
    if (leftSpeed > speedLimit)
      leftSpeed = speedLimit;
    else if (leftSpeed < -speedLimit)
      leftSpeed = -speedLimit;

    if (rightSpeed > speedLimit)
      rightSpeed = speedLimit;
    else if (rightSpeed < -speedLimit)
      rightSpeed = -speedLimit;

    //DRIFT ERROR
    //error = average(fabs(enc(LeftTop)), fabs(enc(LeftBot))) - average(fabs(enc(RightTop)), fabs(enc(RightBot)));
    error = average(LeftTop.current(), LeftBot.current()) - average(RightTop.current(), RightBot.current());
    float drift = kp_c * error;


    LeftTop.spin(directionType::fwd, dir * (leftSpeed-drift), voltageUnits::mV);
    LeftBot.spin(directionType::fwd, dir * (leftSpeed-drift), voltageUnits::mV);
    RightTop.spin(directionType::fwd, dir * (rightSpeed+drift), voltageUnits::mV);
    RightBot.spin(directionType::fwd, dir * (rightSpeed+drift), voltageUnits::mV);
    
    
    if(fabs(errorL) < 10 && fabs(errorR) < 10){
      break;
    }
    //So that it doesn't take up all the RAM
    wait(20);
  }
  StopMove(brake);
  wait(10);
}

// POSITIVE - LEFT
// NEGATIVE - RIGHT
void pidTurn(float degrees, float turnSpeed, float timeout) {
  resetEncoder();
  Brain.resetTimer();
  T3 = 0;
  Inertial.resetRotation();
  // GlobalGyro = 0;
  float kp = 2.15, ki = 0.00175, kd = 1.25;
  float dir = 1;
  float error;
  float totalError = 0;
  float prevError;
  if (degrees < 0) {
    dir = -1;
  }

  while (T3 < timeout) {
    // calculate error
    error = fabs(degrees) - fabs(Inertial.rotation());

    // calculate integral
    // LIMIT INTEGRAL VALUES
    // error is in active zone for integral to activate
    if (fabs(error) < 50 && error != 0 && T3 > 0) {
      totalError += error;
    } else {
      totalError = 0;
    }
    float integral = totalError;
    // calculate derivative
    float derivative = error - prevError;
    prevError = error;

    //calculate speed
    float speed = kp * error + ki * integral + kd * derivative;

    // LIMIT SPEED
    if (speed > turnSpeed)
      speed = turnSpeed;
    if (speed < -turnSpeed)
      speed = -turnSpeed;

    rightDrive(speed * dir);
    leftDrive(-speed * dir);
    if (fabs(error) < 5) {
      break;
    }
    wait(16);
  }
  StopMove(brake);
  wait(16);
}

void curvedMove(float dist, float speed, float curve, char side) {
  resetEncoder();
  float leftSpeed = speed;
  float rightSpeed = speed;

  float dir = 1;
  if(dist< 0){
    dir = -1;
  }

  //calculate distance
  float FWDCount = fabs(dist*330/(4.0*pi));

  if(side  == 'R') { // Turns Right More
    if(speed > curve) { // Make sure that our curve is less than the actual speed otherwise go straight
      rightSpeed -= curve;
    }

    while(fabs(enc(LeftTop)) < FWDCount){
      rightSlew(rightSpeed);
      leftSlew(leftSpeed);
      wait(10);
    }

  } 
  else if (side == 'L'){ // Turns Left More
    if(speed > curve) { // Make sure that our curve is less than the actual speed otherwise go straight
      leftSpeed -= curve;
    }

    while(fabs(enc(RightTop)) < FWDCount){
      rightSlew(rightSpeed);
      leftSlew(leftSpeed);
      wait(10);
    }

  }

  StopMove(brake);
  wait(10);
  
}

void StrafeMove(double dist, float speed, float timeout) {
  resetEncoder();
  T3 = 0;
  float dir = 1;
  if (dist < 0) {
    dir = -1;
  }
  float tempdir = dir;
  float SideCount = fabs(dist * 362 / (4.0 * pi));
  while ((fabs(enc(LeftTop)) < SideCount) && T3 < timeout) {
    if (fabs(enc(LeftTop)) < fabs((enc(RightTop)))) {
      RightTop.spin(directionType::rev, (speed+22) * tempdir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, speed * tempdir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, speed * tempdir, velocityUnits::pct);
      LeftBot.spin(directionType::rev, (speed+22) * tempdir, velocityUnits::pct);
    }
    if (fabs(enc(LeftTop)) > fabs(enc(RightTop))) {
      RightTop.spin(directionType::rev, speed * tempdir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, (speed+22) * tempdir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, (speed+22) * tempdir,velocityUnits::pct);
      LeftBot.spin(directionType::rev, speed * tempdir, velocityUnits::pct);
    }
    RightTop.spin(directionType::rev, speed * tempdir, velocityUnits::pct);
    LeftTop.spin(directionType::fwd, speed * tempdir, velocityUnits::pct);
    RightBot.spin(directionType::fwd, speed * tempdir, velocityUnits::pct);
    LeftBot.spin(directionType::rev, speed * tempdir, velocityUnits::pct);
  }
  RightTop.stop(brakeType::brake);
  RightBot.stop(brakeType::brake);
  LeftTop.stop(brakeType::brake);
  LeftBot.stop(brakeType::brake);
}

//POSTIVE - right
//NEGATIVE - left
void pidStrafe(float dist, float speed, float timeout){
  resetEncoder();
  Brain.resetTimer();
  //set gains
  float kp = 1000, ki = 0, kd = 0;
  float kp_c = 150;

  //setting directions
  float dir = 1;
  if(dist < 0){
    dir = -1;
  }

  //create variable
  float errorDiagL, errorDiagR;
  float prevErrorL = 0, prevErrorR = 0;
  float totalErrorL = 0,totalErrorR = 0;
  
  float errorTD, errorBD;
  float integralActiveZone = inchToTicks(5);
  
  float desiredValue = fabs(dist * 400/(4.0*pi));
  float speedLimit = (speed) * 127;
  //resetTime
  T3 = 0;

  while(T3 < timeout){
    //PROPORTIONAL
    errorDiagL = desiredValue - average(fabs(enc(LeftTop)), fabs(enc(RightBot)));
    errorDiagR = desiredValue - average(fabs(enc(RightTop)), fabs(enc(LeftBot)));

    float proportionL = kp * errorDiagL;
    float proportionR = kp * errorDiagR;

    //INTEGRAL
    if(fabs(errorDiagL) < integralActiveZone && errorDiagL!= 0 && T3 > 0){totalErrorL += errorDiagL;}
    else {totalErrorL = 0;}

    if(fabs(errorDiagR) < integralActiveZone && errorDiagR != 0 && T3 > 0){totalErrorR += errorDiagR;}
    else {totalErrorR = 0;}

    float integralL =  ki * totalErrorL;
    float integralR = ki * totalErrorR;

    //DERIVATIVE
    float derivativeL = kd * (errorDiagL - prevErrorL);
    prevErrorL = errorDiagL;

    float derivativeR = kd * (errorDiagR - prevErrorR);
    prevErrorR = errorDiagR;
    
    //HARD LIMIT FOR DERIVATIVE
    if(errorDiagL == 0){
      derivativeL = 0;
    }
    if(errorDiagR == 0){
      derivativeR = 0;
    }

    //CALCULATE SPEED
    float leftDiag = proportionL + integralL + derivativeL;
    float rightDiag = proportionR + integralR + derivativeR;

    //HARD LIMIT FOR SPEED
    if (leftDiag > speedLimit)
      leftDiag = speedLimit;
    else if (leftDiag < -speedLimit)
      leftDiag = -speedLimit;

    if (rightDiag > speedLimit)
      rightDiag = speedLimit;
    else if (rightDiag < -speedLimit)
      rightDiag = -speedLimit;

    //DRIFT CORRECTION
    errorTD = fabs(LeftTop.current()) - fabs(RightTop.current());
    errorBD = fabs(LeftBot.current()) - fabs(RightBot.current());
    float driftTP = kp_c * errorTD;
    float driftBP = kp_c * errorBD;

    //COMMAND MOTORS
    LeftTop.spin(directionType::fwd, dir * (leftDiag - driftTP), voltageUnits::mV);
    LeftBot.spin(directionType::fwd, -1 * dir * (rightDiag - driftBP), voltageUnits::mV);
    RightTop.spin(directionType::fwd, -1 * dir * (rightDiag + driftTP), voltageUnits::mV);
    RightBot.spin(directionType::fwd, dir * (leftDiag + driftBP),voltageUnits::mV);

    if(fabs(errorDiagL) < 10 && fabs(errorDiagR) < 10){
      break;
    }
    wait(16);
  }
  StopMove(brake);
  wait(10);
}
/*
************************
|     USER CONTROL     |
************************ */


int L_switch;
int R_switch;

void driveControl() {
  int deadzone = 15;
  if (abs(ch1) > deadzone || abs(ch3) > deadzone || abs(ch4) > deadzone + 20) // deadzone for controller
  {
    float ts = 25;
    if(bA && !autonSelect) {
      L_switch = 1;
    } else if(bY) {
      R_switch = 1;
    } 
    else {
      L_switch = 0;
      R_switch = 0;
    }
    float LSpeed = (ts * L_switch);
    float RSpeed = (ts * R_switch);

    LeftTop.spin(directionType::fwd, (ch3 + ch1 + ch4) + LSpeed - RSpeed, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, (ch3 + ch1 - ch4) + LSpeed - RSpeed, velocityUnits::pct);
    RightTop.spin(directionType::fwd, (ch3 - ch1 - ch4) - LSpeed + RSpeed, velocityUnits::pct);
    RightBot.spin(directionType::fwd, (ch3 - ch1 + ch4)  - LSpeed + RSpeed, velocityUnits::pct);
  } else if (bUp) {
    float ts = 10;
    if(bA && !autonSelect) {
      L_switch = 1;
    } else if(bY) {
      R_switch = 1;
    } 
    else {
      L_switch = 0;
      R_switch = 0;
    }
    float LSpeed = (ts * L_switch);
    float RSpeed = (ts * R_switch);

    LeftTop.spin(directionType::fwd, 20 + LSpeed - RSpeed, velocityUnits::pct);
    LeftBot.spin(directionType::fwd, 20 + LSpeed - RSpeed, velocityUnits::pct);
    RightTop.spin(directionType::fwd, 20 - LSpeed + RSpeed, velocityUnits::pct);
    RightBot.spin(directionType::fwd, 20 - LSpeed + RSpeed, velocityUnits::pct);
  } else if(bA && !autonSelect) {
    leftDrive(25);
    rightDrive(-25);
  } else if(bY) {
    leftDrive(-25);
    rightDrive(25);
  }  else {
    LeftTop.stop(brakeType::brake);
    LeftBot.stop(brakeType::brake);
    RightTop.stop(brakeType::brake);
    RightBot.stop(brakeType::brake);

  }
}

