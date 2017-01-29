#pragma once

#include <iostream>
#include <string>
#include <map>

typedef std::map <std::string, size_t> WordsCountMap;

void LowerCaseString(std::string & str);
WordsCountMap CountWordsInFile(std::istream & input);
void OutWordsCountMap(std::ostream & output, WordsCountMap wordsCount);