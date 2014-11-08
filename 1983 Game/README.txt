TO WORK WITH TELEOP
1) Start RobotC
2) Goto Menu Robot > Platform Type> External Motor/Servo Controllers
3) Open teleop.c
4) Scroll unilt you see the lines that start with #include
5) Ignore the first #include line, "JoystickDriver.c", it's a system file
6) The next include lines tell you what files to open.
7) Open drivebase.c
8) Open OI.c
9) Open any other files that show up in the #include section.
10) Go back to teleop.c and compile it.


TO WORK WITH AUTONOMUS
1) Start RobotC
2) Goto Menu Robot > Platform Type> External Motor/Servo Controllers
3) Open autonomous.c
4) Scroll unilt you see the lines that start with #include
5) Ignore the first #include line, "JoystickDriver.c", it's a system file
6) The next include lines tell you what files to open.
7) Open drivebase.c
8) Open any other files that show up in the #include section.
9) Go back to autonomous.cand compile it.


TO TEST THE ARM
1) Start RobotC
2) Goto Menu Robot > Platform Type> External Motor/Servo Controllers
3) Open test_arm.c
4) Scroll unilt you see the lines that start with #include
5) Ignore the first #include line, "JoystickDriver.c", it's a system file
6) The next include lines tell you what files to open.
7) Open OI.c
8) Open arm.c
9) Open any other files that show up in the #include section.
10) Go back to teleop.c and compile it.
