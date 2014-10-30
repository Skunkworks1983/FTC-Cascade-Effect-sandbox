

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                   - Moving Forward then Backward-                                      *|
|*                                            ROBOTC on NXT                                               *|
|*                                                                                                        *|
|*  This program runs your taskbot in a square five times.                                                *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*    1)  To change the forward movement speed replace the two "100"'s with the desired speed number.     *|
|*        (Negative numbers are the reverse equivalent.)                                                  *|
|*    2)  To change the duration of the movement, replace the "4000" with the desired number of           *|
|*        milliseconds.                                                                                   *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port C                  motorC              NXT                 Right motor                         *|
|*    Port B                  motorB              NXT                 Left motor                          *|
\*---------------------------------------------------------------------------------------------------4246-*/

void forward()
{
   motor[motorC] = 100;     // Motor C is run at a 100 power level.
   motor[motorB] = 100;     // Motor B is run at a 100 power level.
   wait1Msec(4000);         // The program waits 4000 milliseconds before running further code.
}

void backward ()
{
   motor[motorC] = -100;    // Motor C is run at a -100 power level.
   motor[motorB] = -100;    // Motor B is run at a -100 power level.
   wait1Msec(4000);         // The program waits 4000 milliseconds before running further code.
}
