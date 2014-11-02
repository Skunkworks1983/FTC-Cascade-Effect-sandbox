/*
OI (Operator Interface) is the ONLY file that should be aware of joystick buttons and axes.
OI.c contains a collecton of "intuitive" functions like raiseArm(), lowerArm() so other developers
don't have to worry about how the joystics are matched.  See test_arm.c for an example
* TO-DOs
*   o When you accomplish a task below, change the first character from 'o' to 'x'
*   o Add bool isTankMode(TJoystick &joystick)
*     function should return bool, like lowerArm(), it should return true if joy1Btn(2) == 0
*   o Add bool isMecanumMode(TJoystick &joystick), it should return true if joy1Btn(2) == 1
*     function should return bool, like lowerArm()
*   o Add short tankDriveLeftThrottle(TJoystick &joystick)
*     function should return short, Positive for foward; negative for reverse.
*   o Add short tankDriveRightThrottle(TJoystick &joystick)
*     function should return short, Positive for foward; negative for reverse.
*   o Add short mecanumFrontBackSpeed(TJoystick &joystick)
*     function should return short, Positive for foward; negative for reverse.
*   o Add shortmecanumLeftRightSpeed(TJoystick &joystick)
*     function should return short, Positive for leftward motion, negative for right.
*/

#include "JoystickDriver.c"
bool lowerArm (TJoystick &joystick)
{
	return (joy1Btn(2) == 1);
}
bool raiseArm (TJoystick &joystick)
{
	return (joy1Btn(4) == 1);
}
