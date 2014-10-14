/* RobotC Hellow World File */
/* From http://byterevel.com/2011/09/28/robotc-tutorial-2-hello-world-and-programming */

task main() //the start of all RobotC programs
{// the start of the function
  eraseDisplay();      //clear the NXT display
  // now to display "Hello World"
  nxtDisplayCenteredBigTextLine(2, "Hello");
  nxtDisplayCenteredBigTextLine(4, "World!");
  
  while (true);
    //loop until program is terminated (so we can read the display)
}//the end of the function
