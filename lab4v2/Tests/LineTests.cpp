#include "stdafx.h"
#include "PointTests.h"
#include "../lab4v2/LineSegment.h"

struct LineFixture_
{
	CLineSegment line;
	LineFixture_()
		:line({ 0, 100 }, {100, 100 }, "#ff0000")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Line, LineFixture_)
BOOST_AUTO_TEST_CASE(line_has_zero_area)
{
	BOOST_CHECK(line.GetArea() == 0);
}

BOOST_AUTO_TEST_CASE(line_has_a_perimeter)
{
	BOOST_CHECK(line.GetPerimeter() == 100);
}

BOOST_AUTO_TEST_CASE(line_get_start_point)
{
	IsPointsEqual(line.GetStartPoint(), { 0, 100 });
}

BOOST_AUTO_TEST_CASE(line_get_end_point)
{
	IsPointsEqual(line.GetEndPoint(), { 100, 100 });
}

BOOST_AUTO_TEST_CASE(line_to_string)
{
	BOOST_CHECK(line.ToString() == "Line:   S = 0  P = 100  ColorOutline = #ff0000");
}
BOOST_AUTO_TEST_SUITE_END()