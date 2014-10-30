#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          arm,           tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     mLeft,         tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     mRight,        tmotorNormal, openLoop, reversed, encoder)

bool isOnBlueSide;  // Which side are we running from?
int startDelay; // How many seconds to wait before starting


// Get a clean button press
int getButton() {
  while (nNxtButtonPressed != -1) {} // Wait until nothing is pressed
  while (nNxtButtonPressed == -1) {} // Wait until the user presses something

  int button = nNxtButtonPressed; // Remember which button was pressed
  while (nNxtButtonPressed != -1) {} // Wait for them to release it again

  return button;
}
// Ask which side we're running from
void promptSide() {
  eraseDisplay(); // Clear the screen
  displayTextLine(0, "Which side?"); // Prompt the user
  displayTextLine(1, "Left = blue");
  displayTextLine(2, "Right = red");

  bool done = false;
  while (!done) { // Repeat until they press a valid button (left or right)
    switch (getButton()) {  // Get a button press
      case 1: // Right arrow button
        isOnBlueSide = false;
        done = true;
        break;

      case 2: // Left arrow button
        isOnBlueSide = true;
        done = true;
        break;
    }
  }

  eraseDisplay(); // Clear the screen again
}
// Ask how long to wait before starting
void promptDelay() {
  bool done = false;
  while (!done) { // Repeat until they have chosen a number
    eraseDisplay(); // Clear the screen
    displayTextLine(0, "%d", startDelay);  // Display the current number

    switch (getButton()) {  // Get a button
      case 1: // Right arrow button
        startDelay++; // Increase by a second
        break;

      case 2: // Left arrow button
        startDelay--; // Decrease by a second, but don't go below 0
        if (startDelay < 0) startDelay = 0;
        break;

      case 3: // Orange square button
        done = true;  // We are done here.
        break;
    }
  }
  eraseDisplay(); // Clear the screen again
}
// Turn right (if on the blue side)
void turnRight(int power, int distance) {
  nMotorEncoder[mLeft] = 0; // Reset both encoders
  nMotorEncoder[mRight] = 0;

  if (isOnBlueSide) { // Flip based on which side we're on
    motor[mLeft] = power;
    motor[mRight] = -power;
  } else {
    motor[mLeft] = -power;
    motor[mRight] = power;
  }
  // Wait until the encoders have reached their goal
  while (abs(nMotorEncoder[mLeft] - nMotorEncoder[mRight]) / 2 <= distance) {}

  motor[mLeft] = 0; // Stop both motors
  motor[mRight] = 0;
}
