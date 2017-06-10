#include "stdafx.h"
#include "../ArraySum/ArraySum.h"
#include <vector>
#include <string>

using namespace std;

BOOST_AUTO_TEST_SUITE(ArraySum_function)
	
	BOOST_AUTO_TEST_CASE(caluclate_sum_of_integers)
	{
		vector<int> arr = { 3, 5, -8, 6, 7 };
		int sum = ArraySum(arr);
		int answer = 13;
		BOOST_CHECK_EQUAL(sum, answer);
	}

	BOOST_AUTO_TEST_CASE(caluclate_sum_of_doubles)
	{
		vector<double> arr = { 1.3, 0.0, -0.2 };
		double sum = ArraySum(arr);
		double answer = 1.1;
		BOOST_CHECK_EQUAL(sum, answer);
	}

	BOOST_AUTO_TEST_CASE(caluclate_sum_of_strings)
	{
		vector<string> arr = { "Hello", " ", "world!" };
		string sum = ArraySum(arr);
		string answer = "Hello world!";
		BOOST_CHECK_EQUAL(sum, answer);
	}

	BOOST_AUTO_TEST_SUITE(returns_default_type_value_when)

		BOOST_AUTO_TEST_CASE(array_of_integers_is_empty)
		{
			vector<int> arr;
			int sum = ArraySum(arr);
			BOOST_CHECK_EQUAL(sum, 0);
		}
		
		BOOST_AUTO_TEST_CASE(array_of_strings_is_empty)
		{
			vector<string> arr;
			string sum = ArraySum(arr);
			BOOST_CHECK_EQUAL(sum, "");
		}
		
		BOOST_AUTO_TEST_CASE(array_of_doubles_is_empty)
		{
			vector<double> arr;
			double sum = ArraySum(arr);
			BOOST_CHECK_EQUAL(sum, 0.0);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()