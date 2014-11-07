/*
OI (Operator Interface) is the only file that should be aware of joystick buttons and axes.
OI.c contains a collecton of "intuitive" functions like raiseArm(), lowerArm() so other developers
don't have to worry about how the joystics are matched.  See test_arm.c for an example
*/


#include "JoystickDriver.c"
bool OI_should_lowerArm (TJoystick &joystick)
{
	return (joy2Btn(2) == 1);
}
bool OI_should_raiseArm (TJoystick &joystick)
{
	return (joy2Btn(4) == 1);
}
bool OI_is_in_tank_drive (TJoystick &joystick)
{
	return (joy1Btn(2) == 0);
}
bool OI_is_in_translate_drive (TJoystick &joystick)
{
	return (joy1Btn(2) == 1);
}
