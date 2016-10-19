// compare.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool CompareFiles(ifstream & file1, ifstream & file2, int & numberStr)
{
	string s1, s2;

	while (!file1.eof() || !file2.eof())
	{
		getline(file1, s1);
		getline(file2, s2);
		numberStr++;
		if (s1 != s2)
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count." << endl;
		return 1;
	}

	ifstream file1(argv[1]);
	ifstream file2(argv[2]);

	if (!file1.is_open())
	{
		cout << argv[1] << " not found." << endl;
		return 1;
	}

	if (!file2.is_open())
	{
		cout << argv[2] << " not found." << endl;
		return 1;
	}

	int numberStr = 0;

	if (!CompareFiles(file1, file2, numberStr))
	{
		cout << "File is different. Line number is " << numberStr << endl;
		return 1;
	}

	cout << "Files are equal" << endl;
	return 0;
}

