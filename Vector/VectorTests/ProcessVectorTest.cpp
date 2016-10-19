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

// íå èçìåíÿåò ñîäåðæèìîå âåêòîðà, êîòîðûé íå ñîäåðæèò ïîëîæèòåëüíûõ ÷èñåë
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_no_positive_numbers)
{
	vector<double> numbers = { -4, 0, -3 };
	auto copy(numbers); // àíàëîã vector<double> copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

// íå èçìåíÿåò ñîäåðæèìîå âåêòîðà, êîòîðûé ñîäåðæèò ïðîâåðåííûå ÷èñëà
BOOST_AUTO_TEST_CASE(vector_containing_references)
{
	vector<double> numbers = { 1, 2, 3, 4, 5 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, {4, 5, 6, 7, 8}));
}

// ïðè îáðàáîòêå âåêòîðà ñ îäíèì ïîëîæèòåëüíûì ÷èñëîì
BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_one_positive_number)
// äîëæíà äîáàâèòü ýòî ÷èñëî êî âñåì ýëåìåíòàì âåêòîðà
BOOST_AUTO_TEST_CASE(should_add_this_number_to_each_element)
{
	vector<double> numbers = { -1, 3.5 };
	ProcessVector(numbers);

	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (-1 + 3.5), (3.5 + 3.5) }
	));
	// Àíàëîãè÷íî ñëåäóþùåé èíñòðóêöèè:
	// BOOST_CHECK(numbers == vector<double>({ (-1 + 3.5), (3.5 + 3.5) }));
}
BOOST_AUTO_TEST_SUITE_END()

// ïðè îáðàáîòêå âåêòîðà ñ íåñêîëüêèìè ïîëîæèòåëüíûìè ýëåìåíòàìè
BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_several_positive_elements)
// äîëæåí äîáàâèòü èõ ñðåäíåå àðèôìåòè÷åñêîå ê êàæäîìó ýëåìåíòó
BOOST_AUTO_TEST_CASE(should_add_their_average_to_each_element)
{
	vector<double> numbers = { -1, 1, 2, 3 };
	ProcessVector(numbers);

	const double average = (1.0 + 2.0 + 3.0) / 3;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (-1 + average), (1 + average), (2 + average), (3 + average) }
	));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
