#include "stdafx.h"
#include "../GeneratePrimeNumbersSet/GeneratePrimeNumbersSet.h"
#include <boost/date_time/posix_time/posix_time.hpp>

BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)

	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_0)
	{
		std::set<int> correctResult = {};
		BOOST_CHECK(GeneratePrimeNumbersSet(0) == correctResult);
	}

	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_10)
	{
		std::set<int> correctResult = { 2, 3, 5, 7 };
		BOOST_CHECK(GeneratePrimeNumbersSet(10) == correctResult);
	}

	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_100)
	{
		std::set<int> correctResult = { 2, 3, 5, 7, 11, 13, 17, 19, 23,
			29, 31, 37, 41, 43, 47, 53, 59,
			61, 67, 71, 73, 79, 83, 89, 97 };
		BOOST_CHECK(GeneratePrimeNumbersSet(100) == correctResult);
	}

	BOOST_AUTO_TEST_CASE(generate_with_upper_bound_is_out_of_range)
	{
		std::set<int> correctResult = {};
		std::set<int> result = GeneratePrimeNumbersSet(100000001);
		BOOST_CHECK(result == correctResult);
	}

	BOOST_AUTO_TEST_CASE(check_size_vector_with_prime_numbers)
	{
		BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(100000000).size(), 5761455);
	}

BOOST_AUTO_TEST_SUITE_END()