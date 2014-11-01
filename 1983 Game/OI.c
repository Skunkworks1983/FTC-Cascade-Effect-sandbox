#include "JoystickDriver.c"
bool lowerArm (TJoystick &joystick)
{
	return (joy1Btn(2) == 1);
}
