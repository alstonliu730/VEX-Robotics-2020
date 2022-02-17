#include "drive.h"

/*
************************
|    AUTONOMOUS        |
************************ */

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
    } else if (fabs(encRaw(liftLeft)) < fabs(encRaw(liftRight))){
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

/*
************************
|     USER CONTROL     |
************************ */

void liftControl() {
  if (bL1) {
    liftLeft.spin(directionType::fwd, 100, velocityUnits::pct);
    liftRight.spin(directionType::fwd, 100, velocityUnits::pct);
    liftSupport.spin(directionType::fwd, 100, velocityUnits::pct);
  } else if (bL2) {
    liftLeft.spin(directionType::rev, 75, velocityUnits::pct);
    liftRight.spin(directionType::rev, 75, velocityUnits::pct);
    liftSupport.spin(directionType::rev, 75, velocityUnits::pct);
  } else if (bX) {
    liftLeft.spin(directionType::rev, 25,velocityUnits::pct);
    liftRight.spin(directionType::rev, 25, velocityUnits::pct);
    liftSupport.spin(directionType::rev, 25, velocityUnits::pct);
  } else {
    liftLeft.stop(brakeType::hold);
    liftRight.stop(brakeType::hold);
    liftSupport.stop(brakeType::hold);
  }
}