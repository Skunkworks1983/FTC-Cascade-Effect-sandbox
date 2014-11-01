/*
OI (Operator Interface) is the only file that should be aware of joystick buttons and axes. 
OI.c contains a collecton of "intuitive" functions like raiseArm(), lowerArm() so other developers
don't have to worry about how the joystics are matched.  See test_arm.c for an example
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
