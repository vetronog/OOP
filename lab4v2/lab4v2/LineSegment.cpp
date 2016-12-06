#include "stdafx.h"
#include "LineSegment.h"
#include "Point.h"

CLineSegment::CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor)
	:IShape("Line"),
	m_startPoint(startPoint),
	m_endPoint(endPoint),
	m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0;
};

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
};

Point const& CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point const& CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetPerimeter() const
{
	double dx = m_startPoint.x - m_endPoint.x;
	double dy = m_startPoint.y - m_endPoint.y;
	return std::hypot(dx, dy);
};

void CLineSegment::AppendProperties(std::ostream & strm) const
{
}

std::istream & operator >> (std::istream &stream, std::shared_ptr<CLineSegment> & lineSegment)
{
	Point startPoint = { 0, 0 };
	Point endPoint = { 0, 0 };
	std::string outlineColor;
	if (
		(stream >> startPoint) && (stream >> endPoint) && (stream >> outlineColor)
		)
	{
		lineSegment = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}