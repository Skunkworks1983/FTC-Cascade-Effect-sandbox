
#include "robotmap.c"
#include "JoystickDriver.c"
task main()
{
	while (true)
	{
		getJoystickSettings(joystick);
		if (joy1Btn(2) == 1) //for moving arm down
		{
			if (SensorValue(touch1) == 0)
			{
				motor [armA] = 100;
				motor [armB] = 100;
			}
			else if (touch1 == (1))
			{
				motor [armA] = 0;
				motor [armB] = 0;
			}
		}
		else if (joy1Btn (4) == 1) //for moving arm up
		{
			if (touch2 == (0))
			{
				motor [armA] = -100;
				motor [armB] = -100;
			}
			else if (touch2 == (1))
			{
				motor [armA] = 0;
				motor [armB] = 0;
			}
		}
	}
}
