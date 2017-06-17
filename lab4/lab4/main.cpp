// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CLineSegment.h"
#include "CRemoteControl.h"
#include "CCircle.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguements count." << endl;
		cout << "Usage lab4.exe <inputFile.txt>" << endl;

		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile)
	{
		cout << "Failed to open file: " << argv[1] << endl;
		return 1;
	}

	CRemoteControl remoteControl(inputFile, cout);

	while (!inputFile.eof() && !inputFile.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	remoteControl.PrintInfo(cout);
}