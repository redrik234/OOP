#include "stdafx.h"
#include "HTML_Encode.h"

using namespace std;

int main()
{
	cout << "Enter the text for encode: " << endl;

	string fileLine, encodeText;

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		getline(cin, fileLine);
		encodeText += HtmlEncode(fileLine);
		cout << encodeText << endl;
		encodeText = "";
	}

	return 0;
}