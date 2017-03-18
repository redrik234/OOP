// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <sstream>
#include "../WordsCount/WordsCount.h"

BOOST_AUTO_TEST_SUITE(WordsCount_function)
BOOST_AUTO_TEST_CASE(cant_count_words_when_empty_input)
{
	WordsCountMap result = {};
	std::istringstream test("");
	BOOST_CHECK(result == CountWordsInFile(test));
}
BOOST_AUTO_TEST_CASE(can_count_words_when_not_empty_input)
{
	WordsCountMap result = { { "hello", 3 },{ "world", 3 } };
	std::istringstream test("Hello World\nHELLO wOrLd\thello world");
	BOOST_CHECK(result == CountWordsInFile(test));
}
BOOST_AUTO_TEST_SUITE_END()

