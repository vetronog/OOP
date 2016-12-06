#include "stdafx.h"
#include "Rectangle.h"
#include "SolidShape.h"
#include "Point.h"
CRectangle::CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor)
	:ISolidShape("Rectangle"),
	m_leftTop(leftTop),
	m_height(height),
	m_width(width),
	m_fillColor(fillColor),
	m_outlineColor(outlineColor)
{
	m_rightBottom = { leftTop.x + width, leftTop.y + height };
}

double CRectangle::GetWidth() const
{
	return m_width;
};

double CRectangle::GetHeight() const
{
	return m_height;
};


Point const& CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

Point const& CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
};

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
};

double CRectangle::GetArea() const
{
	return m_width * m_height;
};

double CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
};

void CRectangle::AppendProperties(std::ostream & strm) const
{
	strm << "  Width = " << m_width
		<< "  Height = " << m_height
		<< "  FillColor = " << GetFillColor();
}

std::istream & operator >> (std::istream &stream, std::shared_ptr<CRectangle> & rectangle)
{
	Point leftPoint = { 0, 0 };
	double width = 0;
	double height = 0;
	std::string outlineColor;
	std::string fillColor;
	if (
		(stream >> leftPoint) && (stream >> width) && (stream >> height) && (stream >> outlineColor) && (stream >>fillColor)
		)
	{
		rectangle = std::make_shared<CRectangle>(leftPoint, width, height, fillColor, outlineColor);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}