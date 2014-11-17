The purpose of this folder is to contain *only* the code to be loaded onto the 2014 FTC Robot at compeittion time, *and nothing else*.   This way,

1) At any point in time, the code in this folder can be loaded onto the robot for driver practice or competition, and it shoudl be *GUARANTEED TO WORK*

2) While driver practice is going on, development can continue in the 1983Game folder.  YOu can do anythign you want there, and be guaranteed not to screw up the competition code.

3) As new features get developed, tested, and perfected in the 1983Game folder, they can be copied ONE AT A TIME into CompeititonCode folder. 

4) During competition, if emergency fixes need to be made, they shoudl be done in 1983Game folder and then copied over once they've been thrououghly tested.

Now, about what's in CompetitionCode, as of Sunda 11/16/14 .... 

Autonomous.c and TeleOp.c were copied from C:\Program Files\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\NXT\Templates.  On Sunday 11/16/14, the pragmas from 1983Game\teleop.c were copied into both TeleOp.c and Autonomous.c

To begin, you'll need to
1) Copy drivebase from 1983Game folder over to here.
2) Copy the contents of 1938Game\teleop'c's while loop into CompetitionCode\TelOp.C
3) Add an #include line to CompetitionCode\TelOp.C
4) Do copy the latch control stuff over until we have a real latch, and we've tested it using code form the 1983Game folder. 
