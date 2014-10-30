bool joy1Flipped = false, // Whether the joysticks are
     joy2Flipped = false; // pretending to be the other one

float mLeftMod = 1, // The modifier for mLeft and mRight
      mRightMod = 1;

void robotSpecial();  // Define this function prototype for
                      // robot-specific code
// Get the value of whoever's pretending to be joy1_y1
int joy1y1() {
  if (joy2Flipped)  // If joy 2 is being joy1, give its value
    return joystick.joy2_y1;
  else if (!joy1Flipped)  // If joy 1 isn't being joy 2, give the real value
    return joystick.joy1_y1;
  else  // If neither are being joy1, return 0
    return 0;
}
int joy1y2() {  // Works the same as joy1y1()
  if (joy2Flipped)
    return joystick.joy2_y2;
  else if (!joy1Flipped)
    return joystick.joy1_y2;
  else
    return 0;
}

task main() {
  waitForStart();

  while (true) {
    getJoystickSettings(joystick);

    // Set the drive motors using controller flipping and
    // sniper modes
    motor[mLeft] = joy1y1() * mLeftMod;
    motor[mRight] = joy1y2() * mRightMod;
    // Perform robot-specific code
    robotSpecial();
    // If we're not connected, stop the robot
    if (bDisconnected) {
      motor[mLeft] = 0;
      motor[mRight] = 0;
    }
  }
}
