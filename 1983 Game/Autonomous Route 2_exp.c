#include "drivebase.c"
task main()
{
	tankdrive (100,100);
	wait_seconds (4);
	tankdrive (100, 25);
	wait_seconds (3);
	tankdrive (80,80);
	wait_seconds (3);
	tankdrive (50, 100);
	wait_seconds (8);

}
