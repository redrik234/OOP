// HTMLEncode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HTML_Encode.h"
#include <map>

using namespace std;

map<char, string> encodeMap =
{
	{ '<', "&lt;" },
	{ '>', "&gt;" },
	{ '\"', "&quot;" },
	{ '\'', "&apos;" },
	{ '&', "&amp;" },
};

string HtmlEncode(string const & text)
{
	string encodeText;

	for (auto ch : text)
	{
		auto locationInMap = encodeMap.find(ch);
		if (locationInMap != encodeMap.end())
		{
			encodeText += locationInMap->second;
		}
		else
		{
			encodeText += ch;
		}
	}

	return encodeText;
}
