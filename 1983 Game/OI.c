#include "JoystickDriver.c"
bool lowerArm (TJoystick &joystick)
{
	return (joy1Btn(2) == 1);
}
bool raiseArm (TJoystick &joystick)
{
	return (joy1Btn(4) == 1);
}
