#include "stdafx.h"
#include "Triangle.h"
#include "SolidShape.h"
#include "Point.h"

CTriangle::CTriangle(Point const& firstVertex, Point const& secondVertex, Point const& thirdVertex, std::string const& outlineColor, std::string const& fillColor)
	:ISolidShape("Triangle"),
	m_fillColor(fillColor),
	m_outlineColor(outlineColor)
{
	m_vertices.push_back(firstVertex);
	m_vertices.push_back(secondVertex);
	m_vertices.push_back(thirdVertex);
}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
};

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
};

Point const& CTriangle::GetVertex1() const
{
	return m_vertices[0];
}

Point const& CTriangle::GetVertex2() const
{
	return m_vertices[1];
}

Point const& CTriangle::GetVertex3() const
{
	return m_vertices[2];
}

double CTriangle::GetArea() const
{
	double semiperimeter = GetPerimeter() * 0.5;
	return std::sqrt(semiperimeter*(semiperimeter - GetSideLength(m_vertices[0], m_vertices[1]))*
		(semiperimeter - GetSideLength(m_vertices[1], m_vertices[2]))*
		(semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))//Формула Герона 
	);
};

double CTriangle::GetSideLength(Point const& firstVertex, Point const& secondVertex) const
{
	double dx = firstVertex.x - secondVertex.x;
	double dy = firstVertex.y - secondVertex.y;
	return std::hypot(dx, dy);
};

double CTriangle::GetPerimeter() const
{
	return GetSideLength(m_vertices[0], m_vertices[1]) +
		GetSideLength(m_vertices[1], m_vertices[2]) +
		GetSideLength(m_vertices[2], m_vertices[0]);
};

void CTriangle::AppendProperties(std::ostream & strm) const
{
	strm << "  FillColor = " << GetFillColor();
}

std::istream & operator >> (std::istream &stream, std::shared_ptr<CTriangle> & triangle)
{
	Point firstVertex = { 0, 0 };
	Point secondVertex = { 0, 0 };
	Point thirdVertex = { 0, 0 };
	std::string outlineColor;
	std::string fillColor;
	if (
		(stream >> firstVertex) && (stream >> secondVertex) && (stream >> thirdVertex) && (stream >> outlineColor) && (stream >> fillColor)
		)
	{
		triangle = std::make_shared<CTriangle>(firstVertex, secondVertex, thirdVertex, fillColor, outlineColor);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}