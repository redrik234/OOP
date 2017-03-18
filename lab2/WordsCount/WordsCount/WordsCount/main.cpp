#include "stdafx.h"
#include "WordsCount.h"

int main()
{
	OutWordsCountMap(std::cout, CountWordsInFile(std::cin));
	return 0;
}