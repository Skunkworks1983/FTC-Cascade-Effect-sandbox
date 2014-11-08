TO WORK WITH TELEOP
1) Start RobotC
2) Goto Menu Robot > Platform Type> External Motor/Servo Controllers
3) Open teleop.c
4) Scroll unilt you see the lines that start with #include
5) Ignore the first #include line, "JoystickDriver.c", it's a system file
6) Right-click the next #include file, it should be "drivebase.c"
7) Go back to teleop.c, right-click the next #include file, it should be "OI.c"
8) Go back to teleop.c and compile it.
9) If you make any changes to drivebase.c or OI.c, check your work by compilng teleop.c
Compiling teleop.c will automatically compile drivebase.c and OI.c.


TO WORK WITH AUTONOMUS
1) Start RobotC
2) Goto Menu Robot > Platform Type> External Motor/Servo Controllers
3) Open autonomous.c
4) Scroll unilt you see the lines that start with #include
5) Ignore the first #include line, "JoystickDriver.c", it's a system file
6) Right-click the next #include file, it should be "drivebase.c"
7) Go back to autonomous.c and compile it.
8) If you make any changes to drivebase.c check your work by compilng autonomous.c 
Compiling autonomous.c will automatically compile drivebase.c.


TO TEST THE ARM
1) Start RobotC
2) Goto Menu Robot > Platform Type> External Motor/Servo Controllers
3) Open test_arm.c
4) Scroll unilt you see the lines that start with #include
5) Ignore the first #include line, "JoystickDriver.c", it's a system file
6) Right-click the next #include file, it should be "OI.c"
7) Go back to test_arm.c, right-click the next #include file, it should be "arm.c"
8) Go back to test_arm.c, and compile it.
9) If you make any changes to arm.c or OI.c, check your work by compilng test_arm.c, 
Compiling test_arm.c, will automatically compile arm.c and OI.c



