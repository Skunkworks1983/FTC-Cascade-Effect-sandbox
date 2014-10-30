#include "JoystickDriver.c"     // Tells ROBOTC to include the driver file for the joystick.
#include "Moving.c"

// Another Tortoise test

task main()
{
 while(true)
  {
    getJoystickSettings(joystick);  // Update Buttons and Joysticks
    tankdrive(joystick.joy1_y1, joystick.joy1_y2);
    /*
    motor[motorC] = joystick.joy1_y1;
    motor[motorB] = joystick.joy1_y2;
    */
  }
}
