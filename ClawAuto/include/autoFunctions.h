#include "pre_auton.h"

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

void StrafeMove(double dist, float speed, float timeout) {
  resetEncoder();
  wait(10);
  T3 = 0;
  float dir = 1;
  if (dist < 0) {
    dir = -1;
  }
  float tempdir = dir;
  float SideCount = fabs(dist * 362 / (4.0 * pi));
  while ((fabs(enc(LeftTop)) < SideCount) && T3 < timeout) {
    if (fabs(enc(LeftTop)) < fabs((enc(RightTop)))) {
      RightTop.spin(directionType::rev, (speed - 10) * tempdir,velocityUnits::pct);
      LeftTop.spin(directionType::fwd, speed * tempdir, velocityUnits::pct);
      RightBot.spin(directionType::fwd, speed * tempdir, velocityUnits::pct);
      LeftBot.spin(directionType::rev, (speed - 10) * tempdir, velocityUnits::pct);
    }
    if (fabs(enc(LeftTop)) > fabs(enc(RightTop))) {
      RightTop.spin(directionType::rev, speed * tempdir, velocityUnits::pct);
      LeftTop.spin(directionType::fwd, (speed - 10) * tempdir,velocityUnits::pct);
      RightBot.spin(directionType::fwd, (speed - 10) * tempdir,velocityUnits::pct);
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


//------------------------
// LIFT CODE
//------------------------
int autoLift(float height, float speed) {
  resetLift();

  float dir = 1;

  if (height < 0) {
    dir = -1;
  }

  float gearRatio = 7.0;
  float encoderTicks = fabs((1800) * (height / (gearRatio * pi)));

  while (fabs(encRaw(liftLeft)) < encoderTicks) {
    if (fabs(encRaw(liftLeft)) > fabs(encRaw(liftRight))) {
      liftLeft.spin(directionType::fwd, dir * (speed - 10), velocityUnits::pct);
      liftRight.spin(directionType::fwd, dir * speed, velocityUnits::pct);
      liftSupport.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    } else if (fabs(encRaw(liftLeft)) < fabs(encRaw(liftRight))) {
      liftLeft.spin(directionType::fwd, dir * speed, velocityUnits::pct);
      liftRight.spin(directionType::fwd, dir * (speed - 10),velocityUnits::pct);
      liftSupport.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    }
    liftLeft.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    liftRight.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    liftSupport.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    wait(16);
  }

  liftLeft.stop(brakeType::hold);
  liftRight.stop(brakeType::hold);
  liftSupport.stop(brakeType::hold);
  wait(10);
  return 1;
}

int autoLift(float height, float speed, float timeout) {
  resetLift();

  float dir = 1;

  if (height < 0) {
    dir = -1;
  }

  float gearRatio = 7.0;
  float encoderTicks = fabs((1800) * (height / (gearRatio * pi)));

  T3 = 0;
  while (fabs(encRaw(liftLeft)) < encoderTicks && T3 < timeout) {
    if (fabs(encRaw(liftLeft)) > fabs(encRaw(liftRight))) {
      liftLeft.spin(directionType::fwd, dir * (speed - 10), velocityUnits::pct);
      liftRight.spin(directionType::fwd, dir * speed, velocityUnits::pct);
      liftSupport.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    } else if (fabs(encRaw(liftLeft)) < fabs(encRaw(liftRight))) {
      liftLeft.spin(directionType::fwd, dir * speed, velocityUnits::pct);
      liftRight.spin(directionType::fwd, dir * (speed - 10),velocityUnits::pct);
      liftSupport.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    }
    liftLeft.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    liftRight.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    liftSupport.spin(directionType::fwd, dir * speed, velocityUnits::pct);
    wait(16);
  }

  liftLeft.stop(brakeType::hold);
  liftRight.stop(brakeType::hold);
  liftSupport.stop(brakeType::hold);
  wait(10);
  return 1;
}

//--------------------------
// CLAW CODE
//--------------------------
void clawGrab(int mode) {
  resetClaw();
  clawMain.setTimeout(600, timeUnits::msec);
  if (mode == 1) {
    clawMain.rotateTo(250, rotationUnits::deg, 100, velocityUnits::pct);
  } else if (mode == 0) {
    clawMain.rotateTo(-250, rotationUnits::deg, 100, velocityUnits::pct);
  }
}

void clawGrab(int mode, double degrees) {
  resetClaw();
  clawMain.setTimeout(600, timeUnits::msec);
  // close
  if (mode == 1) {
    clawMain.rotateTo(250, rotationUnits::deg, 100, velocityUnits::pct, false);
  }
  // open
  else if (mode == 0) {
    clawMain.rotateTo(-250, rotationUnits::deg, 100, velocityUnits::pct, false);
  }

  // custom degrees
  else if (mode == 2) // waits for it to complete
  {
    clawMain.rotateTo(degrees, rotationUnits::deg, 100, velocityUnits::pct);
  } else if (mode == 3) // moves on to next code
  {
    clawMain.rotateTo(degrees, rotationUnits::deg, 100, velocityUnits::pct,false);
  }
}



