// WordsCount.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "WordsCount.h"
#include <algorithm>

using namespace std;

void LowerCaseString(string & str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

WordsCountMap CountWordsInFile(istream & input)
{
	string word;
	WordsCountMap wordsCount;

	while (input >> word)
	{
		LowerCaseString(word);
		++wordsCount[word];
	}

	return wordsCount;
}

void OutWordsCountMap(ostream & output, WordsCountMap wordsCount)
{
	for (auto it : wordsCount)
	{
		output << it.first << "->" << it.second << "\n";
	}
}

