void tankdrive (short leftThrottle, short rightThrottle)
{
	motor [motorA] = (leftThrottle); //for basic tank drive of right side
	motor [motorC] = (leftThrottle); //""
	motor [motorB] = (rightThrottle);//for basic tank drive of left side
	motor [motorD] = (rightThrottle);//""
}
void translatedrive (short direction)
{
	motor[motorA] = direction; //if the A button is on, the x1 will move it side to side
	motor[motorB] = direction;
	motor[motorC] = -direction;
	motor[motorD] = -direction;
}
