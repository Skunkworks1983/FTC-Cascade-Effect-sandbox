///////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Select Tele-Operation Executable Program for FTC Tele-operation Contest Phase
//
// FTC competition programs can be operated in two modes:
// 1. A single user program is used for both autonomous and tele-operated phases of a
//    competition.
// 2. Separate programs are used for each of the two phases.
//
// When dual mode is used, the name of the tele-operated phase is stored in a text file.
// The Competition field management system will read this file to obtain the name of the
// program to run for the tele-op phase.
//
// This nifty little utility is used to setup the configuration file.
//
// It also illustrates the use of easily creating programs using standard menus
// with ROBOTC.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma fileExtension("rtm")

#include "MenusAndIcons.c"

string sTextFileName = "FTCConfig.txt"; // Name of the file containg tele-op name

//
// Global variables to hold a list of all executable files
//
const int kMaxFiles = 25;
int nNumbOfFiles;
string sFileNames[kMaxFiles];


///////////////////////////////////////////////////////////////////////////////////////////////////
//
//                    Build List of Executable Files
//
///////////////////////////////////////////////////////////////////////////////////////////////////

void buildFileList()
{
	TFileHandle hFileHandle;
	TFileIOResult nIoResult;
	string sFileName;
	short nFileSize;
  string sFileSearch = "*.rxe"; // Wildcard to search for any executable file

  FindFirstFile(hFileHandle, nIoResult, sFileSearch, sFileName, nFileSize);
	nNumbOfFiles = 0;
	while (nIoResult == ioRsltSuccess)
	{
    stringDelete(sFileName, strlen(sFileName) - 4, 4); // Trim File Extension
    sFileNames[nNumbOfFiles] = sFileName;
    ++nNumbOfFiles;
    FindNextFile(hFileHandle, nIoResult, sFileName, nFileSize);
  }
  Close(hFileHandle, nIoResult);
  return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            displayCommandProgress
//
///////////////////////////////////////////////////////////////////////////////////////////////////

void deleteTeleOpConfigFile()
{
	TFileIOResult nIoResult;

  do // Make a loop in case, due to error, there are multiple copies
  {
  	Delete(sTextFileName, nIoResult);
  } while (nIoResult == ioRsltSuccess);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            createTeleopConfigFile
//
///////////////////////////////////////////////////////////////////////////////////////////////////

void createTeleopConfigFile(string &sExecutableName)
{
	TFileIOResult nIoResult;
	TFileHandle hFileHandle;
	short nFileSize;

  deleteTeleOpConfigFile(); // Erase existing file

  // Create the file

  nFileSize = strlen(sExecutableName) + 4;
  OpenWrite(hFileHandle, nIoResult, sTextFileName, nFileSize);
  WriteText(hFileHandle, nIoResult, sExecutableName);
  WriteText(hFileHandle, nIoResult, ".rxe");
  Close(hFileHandle, nIoResult);

  // Display Message

  displayTextLine(5, "");

  if(nIoResult == ioRsltSuccess)
  	displayCenteredTextLine(6, "File Created" );
  else
   displayCenteredTextLine(6, "File Error");

  displayTextLine(7, "");
  wait1Msec(1250);
  return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//                    Menu Processing -- Select an Executable File
//
// Presents a menu of the available executable files on the NXT so that the user can select the
// name of the file to run for the tele-op phase of a FTC competition.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

bool doDualModeFileSelection()
{
	int nFileIndex;
	TMenuAnimationType nDrawType;

	nDrawType = menuOverwrite;
	nFileIndex = 0;
	while (true)
	{
		switch (nNxtButtonTransition)
		{
		case kRightButton:
		  ++nFileIndex;
		  if (nFileIndex >= nNumbOfFiles)
		    nFileIndex = 0;
			nDrawType = menuFromLeft;
		  break;

		case kLeftButton:
		  --nFileIndex;
		  if (nFileIndex < 0)
		    nFileIndex = nNumbOfFiles - 1;
			nDrawType = menuFromRight;
		  break;

		case kEnterButton:
		  createTeleopConfigFile(sFileNames[nFileIndex]);
			nDrawType = menuFromBottom;
		  return true;

		case kExitButton:
		  return false;

		default:
		  break;
		}

		if (nDrawType != menuRefreshComplete)
		{
			drawMenu(nDrawType, iconFileTypeExeFiles, iconFileTypeExeFiles, iconFileTypeExeFiles,
			              sFileNames[nFileIndex], "Pick Teleop File");
			nDrawType = menuRefreshComplete;
		}
	}
}



task main()
{
	nNxtButtonTask = -2;
	nNxtExitClicks = 4;
	buildFileList();
  doDualModeFileSelection();
}
