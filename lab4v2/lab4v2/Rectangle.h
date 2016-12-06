#pragma once
#pragma once
#include "Point.h"
#include "SolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	Point const& GetLeftTop() const;
	Point const& GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	Point m_leftTop;
	Point m_rightBottom;
	double m_width;
	double m_height;
	std::string m_outlineColor;
	std::string m_fillColor;
};
std::istream & operator >> (std::istream &stream, std::shared_ptr<CRectangle> & rectangle);