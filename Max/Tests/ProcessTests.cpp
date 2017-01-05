#include "stdafx.h"
#include "../Max/FindMaxEl.h"

struct SportsMan
{
	std::string name;
	double height;
	double weight;
};

bool SportsmenAreEqual(const SportsMan &first, const SportsMan &second)
{
	return (first.name == second.name) && (first.height == second.height) && (first.weight == second.weight);
}

bool IsHeightLess(const SportsMan &first, const SportsMan &second)
{
	return (first.height < second.height);
}

bool IsWeightLess(const SportsMan &first, const SportsMan &second)
{
	return (first.weight < second.weight);
}

BOOST_AUTO_TEST_SUITE(FindMax_function)
	
	BOOST_AUTO_TEST_CASE(returns_false_when_vector_is_empty)
	{
		// int
		{
			std::vector<int> vect;
			int max = 0;
			BOOST_CHECK(!FindMax(vect, max));
			BOOST_CHECK(max == 0);
		}
	
		// string
		{
			std::vector<std::string> vect;
			std::string max;
			BOOST_CHECK(!FindMax(vect, max));
			BOOST_CHECK_EQUAL(max, "");
		}
	}

BOOST_AUTO_TEST_CASE(returns_true_when_correct_max_element_of_non_empty_vector_has_been_found)
{
	// int
	{
		std::vector<int> vect = { -27, 0, 0, 27, 28, 27, 28 };
		int max = 0;
		BOOST_CHECK(FindMax(vect, max, [](int a, int b) {return a < b;}));
		BOOST_CHECK_EQUAL(max, 28);
	}

	// string
	{
		std::vector<std::string> vect = { "123", "space", "digit", "z", "xcx", "zxc" };
		std::string max;
		BOOST_CHECK(FindMax(vect, max));
		BOOST_CHECK_EQUAL(max, "zxc");
	}

	// const char
	{
		std::vector<const char*> vect = { "123", "space", "digit", "z", "xcx", "zxc" };
		const char *str = "";

		auto IsConstCharLess = [](const char *a, const char *b)
		{
			return (strcmp(a, b) < 0);
		};

		BOOST_CHECK(FindMax(vect, str, IsConstCharLess));
		BOOST_CHECK_EQUAL(str, "zxc");
	}
}


	const SportsMan Vasil = { "Vasil Zubov", 193.2, 93 };
	const SportsMan Artem = { "Artem Nazarov", 188, 88 };
	const SportsMan Aleks = { "Aleks Strustskii", 180, 95 };
	const SportsMan Pasha = { "Pasha Bardov", 173, 79 };
	
	const std::vector<SportsMan> sportsmen = { Vasil, Artem, Aleks, Pasha};

	BOOST_AUTO_TEST_CASE(Custom_type_Tests)
	{
		std::vector<SportsMan> vect;
		SportsMan man = Vasil;
		BOOST_CHECK(!FindMax(vect, man, IsHeightLess));
		BOOST_CHECK(!FindMax(vect, man, IsWeightLess));
		BOOST_CHECK(SportsmenAreEqual(man, Vasil));
	}
	BOOST_AUTO_TEST_CASE(_type_Tests)
	{
		SportsMan man = Vasil;

		// with max height (Liu Kang)
		BOOST_CHECK(FindMax(sportsmen, man, IsHeightLess));
		BOOST_CHECK(SportsmenAreEqual(man, Vasil));

		// with max weight (KuaiLiang)
		BOOST_CHECK(FindMax(sportsmen, man, IsWeightLess));
		BOOST_CHECK(SportsmenAreEqual(man, Aleks));
	}

BOOST_AUTO_TEST_SUITE_END()
