#include "drivebase.c"
task main()
{
	tankdrive (100,100);
	wait1Msec (4000);
	tankdrive (100, 25);
	wait1Msec (3000);
	tankdrive (80,80);
	wait1Msec (3000);
	tankdrive (50, 100);
	wait1Msec (8000);

}
