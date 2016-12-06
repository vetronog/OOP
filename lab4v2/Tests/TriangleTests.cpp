#include "stdafx.h"
#include "PointTests.h"
#include "../lab4v2/Triangle.h"


struct TriangleFixture_
{
	CTriangle triangle;
	TriangleFixture_()
		:triangle({ 0, 0 }, { 0, 100 }, { 100, 100 }, "#0000ff", "#ff0000")
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle, TriangleFixture_)


	BOOST_AUTO_TEST_CASE(triangle_get_vertex)
	{
		IsPointsEqual(triangle.GetVertex1(), { 0, 0 });
		IsPointsEqual(triangle.GetVertex2(), { 0, 100 });
		IsPointsEqual(triangle.GetVertex3(), { 100, 100 });
	}

	BOOST_AUTO_TEST_CASE(triangle_has_a_perimeter)
	{
		BOOST_CHECK_CLOSE_FRACTION(triangle.GetPerimeter(), 341.421, 0.001);
	}
	
	BOOST_AUTO_TEST_CASE(triangle_has_a_area)
	{
		BOOST_CHECK(triangle.GetArea() == 5000);
	}

	BOOST_AUTO_TEST_CASE(triangle_get_outline_color)
	{
		BOOST_CHECK(triangle.GetOutlineColor() == "#0000ff");
	}
	BOOST_AUTO_TEST_CASE(triangle_get_fill_color)
	{
		BOOST_CHECK(triangle.GetFillColor() == "#ff0000");
	}
	
	BOOST_AUTO_TEST_CASE(triangle_to_string)
	{
		BOOST_CHECK(triangle.ToString() == "Triangle:   S = 5000  P = 341.421  ColorOutline = #0000ff  FillColor = #ff0000");
	}

BOOST_AUTO_TEST_SUITE_END()