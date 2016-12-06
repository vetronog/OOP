#include "stdafx.h"
#include "PointTests.h"
#include "../lab4v2/circle.h"


struct CircleFixture_
{
	CCircle circle;
	CircleFixture_()
		:circle({ 0, 0 },50 , "#f0f0f0", "#0f0f0f")
	{}
};

BOOST_FIXTURE_TEST_SUITE(circle, CircleFixture_)


BOOST_AUTO_TEST_CASE(circle_get_vertex)
{
	IsPointsEqual(circle.GetCenter(), { 0, 0 });
}

BOOST_AUTO_TEST_CASE(circle_has_a_perimeter)
{
	BOOST_CHECK_CLOSE_FRACTION(circle.GetPerimeter(), 314.159, 0.001);
}

BOOST_AUTO_TEST_CASE(circle_has_a_area)
{
	BOOST_CHECK_CLOSE_FRACTION(circle.GetArea(), 7853.989, 0.001);
}

BOOST_AUTO_TEST_CASE(circle_get_outline_color)
{
	BOOST_CHECK(circle.GetOutlineColor() == "#f0f0f0");
}
BOOST_AUTO_TEST_CASE(circle_get_fill_color)
{
	BOOST_CHECK(circle.GetFillColor() == "#0f0f0f");
}

BOOST_AUTO_TEST_CASE(circle_to_string)
{
	BOOST_CHECK(circle.ToString() == "Circle:   S = 7853.98  P = 314.159  ColorOutline = #f0f0f0  Radius = 50  FillColor = #0f0f0f");
}

BOOST_AUTO_TEST_SUITE_END()