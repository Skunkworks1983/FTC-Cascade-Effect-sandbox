#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     touchsensor,    sensorTouch)
#pragma config(Motor,  mtr_S1_C2_1,     arm2,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     belt,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     arm1,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
* drivebase.c controls the robot's drive motors.  It is THE ONLY file that knows
* about the drive bases's motors, encoders, and other components. If we use IR sensors
* for navigation, those calls should go here to.
*
* TO-DOs
*   o When you accomplish a task below, change the first character from 'o' to 'x'
*   o Read up on calling motors with encoders.  Try the link below.
*      http://www.tetrixrobotics.com/GettingStartedGuide/files/addons/encoders/Programming/programmingGuides/RC_ProgGuide.pdf
*   o add driveDistance(float DistanceInMeters) to provide support for autonomouse control.
*      start by pretenind dinstance in metters is really the number of "encoder ticks"  Measue  how far the robot goes in 100
*      or 1000 ticks. Figure out how many ticks per meter the robot goes, so you can convert meters to ticks.
*   o modify driveDistance() such ghat negative values make the robot go backwards
*   o add moveLeftRight(float DistanceInMeters) to provide support for autonomouse control.
*     positive for left, negative for ight.
*   o add turnDegree(float degrees)
*   o try removing un-needed pragmas.
*/

#include "OI.c"

void tankdrive (short leftThrottle, short rightThrottle)
{
motor [leftFront] = (leftThrottle); //for basic tank drive of right side
motor [leftBack] = (leftThrottle); //""
motor [rightFront] = (rightThrottle);//for basic tank drive of left side
motor [rightBack] = (rightThrottle);//""
}

void translatedrive (short direction)
{
motor[leftFront] = direction; //if the A button is on, the x1 will move it side to side
motor[leftBack] = direction;
motor[rightFront] = -direction;
motor[rightBack] = -direction;
}


void mecanum_drive (short leftRight, short frontBack, short pivot)
{
	//Create "deadzone" variables. Adjust threshold value to increase/decrease deadzone
	int X2 = 0, Y1 = 0, X1 = 0, threshold = 2;


	//Create "deadzone" for Y1/Ch3
	if(abs(frontBack) > threshold)
		Y1 = frontBack;
	else
		Y1 = 0;
	//Create "deadzone" for X1/Ch4
	if(abs(leftRight) > threshold)
		X1 = leftRight;
	else
		X1 = 0;
	//Create "deadzone" for X2/Ch1
	if(abs(pivot) > threshold)
		X2 = pivot;
	else
		X2 = 0;

	// Modified code, for FTC
	// Not sure if the front motors are A and B, or C and D.
	/*
	motor[leftBack] = Y1 - X2 - X1;
	motor[rightBack] = Y1 - X2 + X1;
	motor[leftFront] = Y1 + X2 + X1;
	motor[rightFront] = Y1 + X2 - X1;
	*/
	if (OI_should_run_half_speed(joystick))
	{
		motor[leftBack] = Y1 + X2 - X1;
		motor[rightBack] = Y1 - X2 + X1;
		motor[leftFront] = Y1 + X2 + X1;
		motor[rightFront] = Y1 - X2 - X1;
	}
	else
	{
		motor[leftBack] = (Y1 + X2 - X1) /2;
		motor[rightBack] = (Y1 - X2 + X1) /2;
		motor[leftFront] = (Y1 + X2 + X1) /2;
		motor[rightFront] = (Y1 - X2 - X1) /2;
	}
		
	// if the code above makes the robot go backwards, comment it out, and
	// uncomment the code belo by deleting the /* and the */

	/*
	motor[leftBack] = Y1 - X2 - X1;
	motor[rightBack] = Y1 - X2 + X1;
	motor[rightFront] = Y1 + X2 + X1;
	motor[leftFront] = Y1 + X2 - X1;

	*/
}

void wait_seconds (short seconds)
{
	wait1Msec (seconds * 1000);

}
