// flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int flipbyte(int number)
{
	int result = 0;

	for (int i = 0; i < 8; i++)
	{
		result = (result << 1);
		if ((number & 1) == 1)
		{
			result = result | 1;
		}
		number = number >> 1;
	}
	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <input byte>\n";
		return 1;
	}

	int num = atoi(argv[1]);

	if ((num == 0) && (*argv[1] != '0'))
	{
		cout << "Invalid argument\n";
		return 1;
	}

	if ((num < 0) || (num > 255))
	{
		cout << "<byte> should be in range [0-255]\n";
		return 1;
	}

	cout << flipbyte(num) << endl;
	return 0;

}


