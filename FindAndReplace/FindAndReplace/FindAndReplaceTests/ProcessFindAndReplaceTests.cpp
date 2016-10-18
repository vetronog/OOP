#include "stdafx.h"
#include "..\FindAndReplace\ProcessFindAndReplace.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

BOOST_AUTO_TEST_CASE(make_first_test)
{
	string subject = "one two th";
	BOOST_CHECK(FindAndReplace(subject, "two", "cat") == "one cat th");
}

BOOST_AUTO_TEST_CASE(make_multi_found_test)
{
	string subject = "one two two th";
	BOOST_CHECK(FindAndReplace(subject, "two", "cat") == "one cat cat th");
}

BOOST_AUTO_TEST_CASE(make_without_found_test)
{
	string subject = "one one one th";
	BOOST_CHECK(FindAndReplace(subject, "two", "cat") == "one one one th");
}

BOOST_AUTO_TEST_CASE(make_empty_replace_test)
{
	string subject = "one two th";
	BOOST_CHECK(FindAndReplace(subject, "two", "") == "one  th");
}


BOOST_AUTO_TEST_SUITE_END()