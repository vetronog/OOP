#include "stdafx.h"
#include "..\Vector\ProcessVector.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Ôóíêöèÿ ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// Ñîçäàåò ïóñòîé âåêòîð èç ïóñòîãî âåêòîðà
	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_no_positive_numbers)
	{
		vector<double> numbers = { 0, -4, 0 };
		auto copy(numbers); // аналог vector<double> copy(numbers);
		ProcessVector(numbers);
		BOOST_CHECK(numbers == copy);
	}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_one_positive_number)

	BOOST_AUTO_TEST_CASE(should_add_this_number_to_each_element)
	{
		vector<double> numbers = { -1, 3.5 };
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, { -2, 0}));
	}

	BOOST_AUTO_TEST_CASE(change_vector_containing_all_positive_numbers)
	{
		vector<double> numbers = {1, 2, 3, 4, 5};
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {2, -13, 6, -11, 10 }));
	}

BOOST_AUTO_TEST_SUITE_END()


