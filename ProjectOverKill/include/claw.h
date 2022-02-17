#include "lift.h"

/*
************************
|    AUTONOMOUS        |
************************ */

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

/*
************************
|     USER CONTROL     |
************************ */

void clawControl() {
  if (bR1) {
    clawMain.spin(directionType::fwd, 100, velocityUnits::pct);
  } else if (bR2) {
    clawMain.spin(directionType::rev, 100, velocityUnits::pct);
  } else {
    clawMain.stop(brakeType::hold);
  }
}
