#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     touch1,         sensorTouch)
#pragma config(Sensor, S4,     touch2,         sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorC,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     armA,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     armB,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     collector,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
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
