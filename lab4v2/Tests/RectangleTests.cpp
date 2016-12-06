#include "stdafx.h"
#include "PointTests.h"
#include "../lab4v2/Rectangle.h"


struct RectangleFixture_
{
	CRectangle rectangle;
	RectangleFixture_()
		:rectangle({ 0, 100 }, 100, 100,  "#ff0000", "#00ff00")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleFixture_)


BOOST_AUTO_TEST_CASE(Rectangle_get_width)
{
	IsPointsEqual(rectangle.GetLeftTop(), { 0, 100 });
}

BOOST_AUTO_TEST_CASE(Rectangle_has_a_perimeter)
{
	BOOST_CHECK_CLOSE_FRACTION(rectangle.GetPerimeter(), 400, 0.001);
}

BOOST_AUTO_TEST_CASE(Rectangle_has_a_area)
{
	BOOST_CHECK_CLOSE_FRACTION(rectangle.GetArea(), 10000, 0.001);
}

BOOST_AUTO_TEST_CASE(Rectangle_get_outline_color)
{
	BOOST_CHECK(rectangle.GetOutlineColor() == "#ff0000");
}
BOOST_AUTO_TEST_CASE(Rectangle_get_fill_color)
{
	BOOST_CHECK(rectangle.GetFillColor() == "#00ff00");
}

BOOST_AUTO_TEST_CASE(Rectangle_to_string)
{
	BOOST_CHECK(rectangle.ToString() == "Rectangle:   S = 10000  P = 400  ColorOutline = #ff0000  Width = 100  Height = 100  FillColor = #00ff00");
}

BOOST_AUTO_TEST_SUITE_END()