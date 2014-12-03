Post-compoetition edit

The purpose of this folder is to contain *only* the code to be loaded onto the 2014 FTC Robot at compeittion time, 
*and nothing else*.   This way,

1) At any point in time, the code in this folder can be loaded onto the robot for driver practice or competition, 
   and it shoudl be *GUARANTEED TO WORK*

2) While driver practice is going on, development can continue in the 1983Game folder.  YOu can do anythign you want 
   there, and be guaranteed not to screw up the competition code.

3) As new features get developed, tested, and perfected in the 1983Game folder, they can be copied ONE AT A TIME into 
  CompeititonCode folder. 

4) During competition, if emergency fixes need to be made, they shoudl be done in 1983Game folder and then copied over 
   once they've been thrououghly tested.

Now, about what's in CompetitionCode, as of Sunday 11/16/14 .... 

Autonomous.c and TeleOp.c were copied from 
C:\Program Files\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\NXT\Templates.  
On Sunday 11/16/14, the pragmas from 1983Game\teleop.c were copied into both TeleOp.c and Autonomous.c

To get to the point we wera at on Saturday 11/15, you'll need to.
1) Copy drivebase from 1983Game folder over to here.
2) Copy the contents of 1938Game\teleop'c's while loop into CompetitionCode\TelOp.C
3) Add an #include line to CompetitionCode\TelOp.C
4) Do NOT  copy the latch control stuff over until we have a real latch, and we've tested it using code form the 1983Game folder. 
5) This should give you a robot that does nothing during autonomous, but allows driver training in teleop.

To start doing someting useful in autonmous.
1) Back in 1983Game\drivebase_experimental.c, functions drive_distance() and turn_degree() should be copied into
   1983Game\drivebase.c include the comments with callibraiton isntrucitons.
2) Still in 1983Game, create AutonmouseCalibration.c  It should call drive_dinstance(1.0) and turn_degree(1.0).

3) Follow the calibraiton instructions that you copied into drivebase.c.  Down worry about turn_degree(), just focus on
   drive_distance()

4) Copy your new drivebase.c from 1983Game over to CompetitionCode. 

5) In CopmpeititonCode\Autonomous.c, just add one drive_distance() call into task_main(),
   right before the while (true) loop. The idea is to put the robot onto the ramp and have it drive itself off.  Easy 20 points.

