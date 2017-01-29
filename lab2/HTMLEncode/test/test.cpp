// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../HTMLEncode/HTML_Encode.h"

BOOST_AUTO_TEST_SUITE(HtmlEncode_function)

BOOST_AUTO_TEST_CASE(makes_empty_string_from_empty_string)
{
	std::string testStr = "";
	BOOST_CHECK(HtmlEncode(testStr) == testStr);
}

BOOST_AUTO_TEST_CASE(makes_string_from_string_without_special_symbols)
{
	std::string testStr = "Cat says meow";
	BOOST_CHECK(HtmlEncode(testStr) == testStr);
}

BOOST_AUTO_TEST_CASE(makes_encoded_string_from_string_with_special_symbols)
{
	std::string testStr = "Cat <says> \"Meow\". M&M's";
	std::string result = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	BOOST_CHECK(HtmlEncode(testStr) == result);
}

BOOST_AUTO_TEST_SUITE_END()

