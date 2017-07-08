// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CLineSegment.h"
#include "CMenu.h"
#include "CCircle.h"

using namespace std;

int main(int argc, char* argv[])
{
	CMenu menu(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!menu.HandleCommand() && !cin.eof())
		{
			cout << "Unknown command!" << endl;
		}
	}

	menu.PrintInfo(cout);
	
}