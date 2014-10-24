#pragma platform(FTC)         // Only works for "FTC" platform. Generate error on other platforms.
#pragma autoStartTasks        // Automatically start this task when the main user program starts.

long msgCnt = 0;
int msgRate = 0;
int msgDelay = 0;

string errorMessage;
const int batteryRefreshInterval = 50;  // 50 * 100Msec = 5 sec
const int msgStatRefreshInterval = 10;
const int msgDelayResetInterval  = 50;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// "Macro" to get a non-volatile copy of the last joystick settings so
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

int readJoyStickMessage()
{
   // message is of the form:
   //     Byte  1: Not used intended for future use.
   //     Byte  2: Autonomous vs TeleOp
   //     Byte  3: 0 indicates stopped, 1 for program start
   //     Byte  4: Joy 1 X1
   //     Byte  5: Joy 1 Y1
   //     Byte  6: Joy 1 X2
   //     Byte  7: Joy 1 Y2
   //     Byte  8: Joy 1 Buttons 1-8
   //     Byte  9: Joy 1 Buttons 9-12, unused 4 bits
   //     Byte 10: Joy 1 TopHat
   //     Byte 11: Joy 2 X1
   //     Byte 12: Joy 2 Y1
   //     Byte 13: Joy 2 X2
   //     Byte 14: Joy 2 Y2
   //     Byte 15: Joy 2 Buttons 1-8
   //     Byte 16: Joy 2 Buttons 9-12, unused 4 bits
   //     Byte 17: Joy 2 TopHat
   //     Byte 18: Null Pad Byte
   ubyte messageBuffer[21];
   int nSizeOfMessage;
   TFileIOResult nBTCmdRdErrorStatus;

   // Check to see if a message is available.
   nSizeOfMessage = cCmdMessageGetSize(mailbox1);

   // If nSizeOfMessage is zero, then no message available to read.
   if (nSizeOfMessage <= 0)
   {
     return 0;
   }

   if (nSizeOfMessage > sizeof(messageBuffer))
   {
     errorMessage= "Length Error " + nSizeOfMessage + "!";
     return -1;
   }

   // have to read the full number of bytes. Under reading will cause an error
   // of ERR_INVALID_SIZE to be returned.
   nBTCmdRdErrorStatus = cCmdMessageRead(messageBuffer, nSizeOfMessage, mailbox1);
   if ( nBTCmdRdErrorStatus != ioRsltSuccess)
   {
      errorMessage = "Read Error " +  nBTCmdRdErrorStatus + "!";
      return -1;
   }

   // msg Cnt - The number of messages received.
   msgCnt++;

   // msg Rate - The Packet to Packet time (non-averaged)in milliseconds.
   msgRate = time1[T1];  // Milliseconds that have passed since we last cleared the timer

   // Msg Delay - The additional packet to packet time relative to the expected
   // 20 messages per second time slice.  20 TPS = 50 milliseconds per message.
   // Both overages and underages are counted... So under by 5 msec on one time slice
   // could be canceled out by over 5 msec on another for a delay of ZERO.
   msgDelay = msgDelay + (msgRate -49);

   return 1;
}

task main()
{
	int rc;
  float batteryLevel = nImmediateBatteryLevel/1000.0;

	eraseDisplay();
  nxtDisplayTextLine(1,"BAT=%g", batteryLevel);
  nxtDisplayCenteredTextLine(7, "Comm Test");

  ClearTimer(T1);  // Time between joystick messages
  ClearTimer(T2);  // Time between reset of msgDelay stats
  ClearTimer(T3);  // Time between Display of the Battery Level
  ClearTimer(T4);  // Time between Display of Message Counts

  while (true)
  {
  	rc =readJoyStickMessage();

  	if (rc < 0)
       nxtDisplayTextLine(2, errorMessage);

    // Joystick message received
    if (rc > 0)
    {

       // Reset msgDelay every 5 seconds... but dont update while waiting
       // for a joystick message.
       if (time100[T2] >= msgDelayResetInterval)
       {
          msgDelay = 0;
          ClearTimer(T2);
       }

       // Update batteryLevel every 5 seconds... but dont update while waiting
       // for a joystick message, dont want updating the battery to count against
       // the stats for reading joystick messages.
       if (time100[T3] >= batteryRefreshInterval)
       {
          batteryLevel = nImmediateBatteryLevel/1000.0;
          nxtDisplayTextLine(1, "BAT=%g",  batteryLevel);

          ClearTimer(T3);
       }

       // Update the displayed message counts every second
       if (time100[T4] >= msgStatRefreshInterval)
       {
          nxtDisplayTextLine(3, "Msg Cnt  = %ld", msgCnt);
          nxtDisplayTextLine(4, "Msg Rate = %d",  msgRate);
          nxtDisplayTextLine(5, "Msg Delay= %d",  msgDelay);
          ClearTimer(T4);
       }

       ClearTimer(T1);       // Start counting milliseconds until the next joystick message arrives.
    }
    // else waiting for joystick message to arrive
  }
}
