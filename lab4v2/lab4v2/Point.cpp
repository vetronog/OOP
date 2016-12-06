#include "stdafx.h"
#include "Point.h"

std::istream & operator >> (std::istream &stream, Point & point)
{
	double pointX = 0;
	double pointY = 0;
	std::string outlineColor;
	if (
		(stream >> pointX) && (stream >> pointY)
		)
	{
		point = Point{ pointX,pointY };
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}