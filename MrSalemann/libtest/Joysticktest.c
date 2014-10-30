#include "JoystickDriver.c"     // Tells ROBOTC to include the driver file for the joystick.
task main()
{
 while(true)
  {
    getJoystickSettings(joystick);  // Update Buttons and Joysticks
    motor[motorC] = joystick.joy1_y1;
    motor[motorB] = joystick.joy1_y2;
  }
}
