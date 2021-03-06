/*
<<<<<<< HEAD
OI (Operator Interface) is the only file that should be aware of joystick buttons and axes.
=======
OI (Operator Interface) is the ONLY file that should be aware of joystick buttons and axes.
>>>>>>> 1615b8363fcc95b3d0613fd9908cbabc7eab9728
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
// arm - slow up and down in left bumpers and triggers. Fast up and down in right bumpers and triggers.
//belt - left side. stick or d pad. Bumpers for toggle slow or fast? bumpers
// no buttons? joysticks have scaling

#include "JoystickDriver.c"
bool OI_should_moveArm (TJoystick &joystick) //arm commands
{
	return joystick.joy2_y2;
}
bool OI_is_in_tank_drive (TJoystick &joystick) //drivebase commands
{
	return (joy1Btn(2) == 0);
}
bool OI_is_in_translate_drive (TJoystick &joystick)
{
	return (joy1Btn(2) == 1); //drivebase commands end
}
bool OI_should_open_latch (TJoystick &joystick) //latch commands
{
	return (joy2Btn(1) == 1);
}
bool OI_should_close_latch (TJoystick &joystick)
{
	return (joy2Btn(3) == 1);
}
bool OI_should_move_belt (TJoystick &joystick)
{
	return joystick.joy2_y1;
}
bool OI_should_run_half_speed (TJoystick &joystick) 
{
	return (joy1Btn(2) == 1);
}

/*
short OI_get_left_throttle(TJoystick &joystick) //looks for joystick inputs
{
	return joystick.joy1_y1;
}

short OI_get_right_throttle(TJoystick &joystick)

{
	return joystick.joy1_y2; //was joystick.joy1_y2 etc but in the TJoystick file (joystickdriver), it shows that it has been shortened to joy1_y2 etc
}

short OI_get_sideways_throttle (TJoystick &joystick)
{
	return joystick.joy1_x1; //looks for joystick inputs end
}*/ // the code doesn't work
