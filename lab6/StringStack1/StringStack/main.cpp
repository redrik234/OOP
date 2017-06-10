// StringStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringStack.h"

using namespace std;

int main()
{
	try
	{
		CStringStack stringStack;
		stringStack.Push("34");
		stringStack.Push("alaxamora");
		cout << stringStack.GetTopElement() << endl;
		stringStack.Pop();
		cout << stringStack.GetTopElement() << endl;
		cout << stringStack.GetSize() << endl;
		stringStack.Clear();
		cout << stringStack.GetSize() << endl;
		cout << stringStack.GetTopElement() << endl;
	}
	catch(logic_error const &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

