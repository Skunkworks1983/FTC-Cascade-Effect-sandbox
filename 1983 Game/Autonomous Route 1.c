#include "latch.c"
#include "drivebase.c"


task main()
{
	latch1_open (); //latch opens to "intitialize"
	tankdrive (100, 100); //forewards
	wait_seconds (12);
	tankdrive (-100,100); //turn 180
	wait_seconds (3);
	tankdrive (-100,-100); //backwards
	wait_seconds (2);
	latch1_close(); //attaches to goal
	tankdrive (-100,100); //turn 40
	wait_seconds (1);
	tankdrive (100,100);//forewardx
	wait_seconds (10);
}
