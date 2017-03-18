#include "stdafx.h"
#include "..\Vector(2lab)\VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(vector_processor_function)

	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(should_devide_each_element_by_max_element_half_when_processing_a_not_empty_vector)
	{
		vector<double> numbers = {6, 12, -6, 1.5};
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {(6 / 6), (12 / 6), (-6 / 6), (1.5 / 6)}));
	}

	BOOST_AUTO_TEST_CASE(makes_vector_when_max_element_is_0)
	{
		vector<double> numbers = {-2, 0};
		ProcessVector(numbers);
		BOOST_CHECK(isinf(numbers[0]) && isnan(numbers[1]));
	}

BOOST_AUTO_TEST_SUITE_END()