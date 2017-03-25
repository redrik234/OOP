// HTMLEncode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HTML_Encode.h"
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<char, string>> encodeArr = 
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
		auto it = find_if(encodeArr.begin(), encodeArr.end(), 
			[=](pair<char, string> symbol) 
		{
			return symbol.first == ch; 
		});

		if (it != encodeArr.end())
		{
			encodeText += it->second;
		}
		else
		{
			encodeText += ch;
		}
	}

	return encodeText;
}