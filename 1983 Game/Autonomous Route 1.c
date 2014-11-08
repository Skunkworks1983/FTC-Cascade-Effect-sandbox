#include "latch.c"
#include "drivebase.c"


task main()
{
	latch1_open (); //latch opens to "intitialize"
	tankdrive (100, 100); //forewards
	wait1Msec (4000);
	tankdrive (-100,100); //turn 180
	wait1Msec (3000);
	tankdrive (-100,-100); //backwards
	wait1Msec (2000);
	latch1_close(); //attaches to goal
	tankdrive (-100,100); //turn 40
	wait1Msec (1000);
	tankdrive (100,100);//foreward
	wait1Msec (10000);
}
