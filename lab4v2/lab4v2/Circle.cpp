#include "stdafx.h"
#include "Circle.h"
#include "SolidShape.h"
#include "Point.h"

CCircle::CCircle(Point const& center, double radius, std::string const& outlineColor, std::string const& fillColor)
	:ISolidShape("Circle"),
	m_center(center),
	m_radius(radius),
	m_outlineColor(outlineColor),
	m_fillColor(fillColor)
{
}

Point const& CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

std::string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
};

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
};

double CCircle::GetArea() const
{
	return M_PI * std::pow(m_radius, 2);
};

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
};

void CCircle::AppendProperties(std::ostream & strm) const
{
	strm << "  Radius = " << m_radius
		<< "  FillColor = " << GetFillColor();
}

std::istream & operator >> (std::istream &stream, std::shared_ptr<CCircle> & circle)
{
	Point firstVertex = { 0, 0 };
	double radius = 0;
	std::string outlineColor;
	std::string fillColor;
	if (
		(stream >> firstVertex) && (stream >> radius) && (stream >> outlineColor) && (stream >> fillColor)
		)
	{
		circle = std::make_shared<CCircle>(firstVertex, radius, fillColor, outlineColor);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}